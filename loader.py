from ctypes import *
import os

avr_cycle_count_t = c_uint64
avr_flashaddr_t = c_uint32

class Avr_symbol(Structure):
    _fields_ = [
        ("addr", c_uint32),
        ("size", c_uint32),
        ("symbol", c_char_p),
    ]

class Py_avr_wrap(Structure):
    _fields_ = [
        ("avr", c_void_p),
        ("stop_addr", c_uint32),
        ("symbolcount", c_uint32),
        ("symbol_addr_sorted", POINTER(POINTER(Avr_symbol))),
        ("symbol_name_sorted", POINTER(POINTER(Avr_symbol))),
    ]

class Avr_save(Structure):
    _fields_ = [
        ("ioend", c_uint16),
        ("ramend", c_uint16),
        ("flashend", c_uint16),
        #avr_cycle_count_t is uint64_t, sure
        ("cycle", c_uint64),
        ("run_cycle_count", avr_cycle_count_t),
        ("run_cycle_limit", avr_cycle_count_t),
        
        ("sreg", c_uint8 * 8),
        
        ("interrupt_state", c_int8),
        #flashaddr is uint32_t
        ("pc", avr_flashaddr_t),
        ("reset_pc", avr_flashaddr_t),
        
        ("copy_flash", c_bool),
        ("flash", POINTER(c_uint8)),
        ("data", POINTER(c_uint8)),
    ]

l0 = CDLL("libsimavr.so.1", RTLD_GLOBAL)
sim_dll = CDLL("test.so", RTLD_GLOBAL)

#configure arg and return types
#util.h

sim_dll.get_symbol.argtypes = [POINTER(Py_avr_wrap), c_char_p]
sim_dll.get_symbol.restype = POINTER(Avr_symbol)
sim_dll.get_data_at_label.argtypes = [POINTER(Py_avr_wrap), c_char_p, POINTER(c_uint32)]
sim_dll.get_data_at_label.restype = POINTER(c_ubyte)
sim_dll.get_sp.argtypes = [POINTER(Py_avr_wrap)]
sim_dll.get_sp.restype = c_uint16
sim_dll.get_ret_addr.argtypes = [POINTER(Py_avr_wrap)]
sim_dll.get_ret_addr.restype = avr_flashaddr_t

#save.h
sim_dll.py_avr_save.argtypes = [POINTER(Py_avr_wrap), c_bool]
sim_dll.py_avr_save.restype = POINTER(Avr_save)
sim_dll.py_avr_restore.argtypes = [POINTER(Py_avr_wrap), POINTER(Avr_save), c_bool]
sim_dll.py_avr_restore.restype = None
sim_dll.py_avr_restore.argtypes = [POINTER(Avr_save)]
sim_dll.py_avr_restore.restype = None

#test_functions.h
sim_dll.supervise_func_call.argtypes = [POINTER(Py_avr_wrap), c_char_p, c_char_p, POINTER(c_uint8), c_uint8, c_int]
sim_dll.supervise_func_call.restype = POINTER(Avr_save)
sim_dll.supervise_func_finalise.argtypes = [POINTER(Py_avr_wrap), POINTER(Avr_save), c_char_p]
sim_dll.supervise_func_finalise.restype = c_int
sim_dll.supervise_func_all.argtypes = [POINTER(Py_avr_wrap), c_char_p, c_char_p, c_char_p, POINTER(c_uint8), c_uint8, c_int, CFUNCTYPE(None, POINTER(Py_avr_wrap))]
sim_dll.supervise_func_all.restype = c_int
sim_dll.jump_to.argtypes = [POINTER(Py_avr_wrap), avr_flashaddr_t]
sim_dll.jump_to.restype = c_int
sim_dll.run_until.argtypes = [POINTER(Py_avr_wrap), avr_flashaddr_t, c_uint32]
sim_dll.run_until.restype = c_int

#main (test_tools.h)
sim_dll.py_sim_init.argtypes = [c_char_p, c_char_p, c_bool]
sim_dll.py_sim_init.restype = POINTER(Py_avr_wrap)
sim_dll.py_sim_reset.argtypes = [POINTER(Py_avr_wrap), c_bool]
sim_dll.py_sim_reset.restype = None
sim_dll.py_sim_terminate.argtypes = [POINTER(Py_avr_wrap)]
sim_dll.py_sim_terminate.restype = None


class Simulator:
    def __init__(self, exe_path: str, mmcu: str = "atmega328p", do_startup: bool = True):
        if not os.path.isfile(exe_path):
            raise FileNotFoundError("cannot find '{}'".format(exe_path))
        self.sim = sim_dll.py_sim_init(c_char_p(bytes(exe_path, encoding="utf-8")), c_char_p(bytes(mmcu, encoding="utf-8")), c_bool(do_startup))

    #this returns the actual object for ease of use
    def get_symbol(self, symbol: str):
        res = sim_dll.get_symbol(self.sim, bytes(symbol, encoding="utf-8"))
        #handle null ptr
        if not res:
            return None
        return res.contents

    def get_data_at_label(self, label: str):
        res_size = c_uint32(0)
        addr = sim_dll.get_data_at_label(self.sim, bytes(label, encoding="utf-8"), byref(res_size))
        if not addr:
            addr = None
        return addr, res_size.value

    def reset(self, do_startup: bool = True):
        sim_dll.py_sim_reset(self.sim, do_startup)

    def __del__(self):
        sim_dll.py_sim_terminate(self.sim)

if __name__ == "__main__":
    sim = Simulator("./main.elf")
    addr, size = sim.get_data_at_label("a.2388")
    addr = cast(addr, POINTER(c_uint16))
    print(hex(addr[0]))
    print(size)
    del sim
