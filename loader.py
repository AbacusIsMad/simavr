from ctypes import *
import os


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

l0 = CDLL("libsimavr.so.1", RTLD_GLOBAL)
sim_dll = CDLL("test_tools.so", RTLD_GLOBAL)

#configure arg and return types
sim_dll.py_sim_init.argtypes = [c_char_p, c_char_p, c_bool]
sim_dll.py_sim_init.restype = POINTER(Py_avr_wrap)
sim_dll.get_symbol.argtypes = [POINTER(Py_avr_wrap), c_char_p]
sim_dll.get_symbol.restype = POINTER(Avr_symbol)
sim_dll.get_data_at_label.argtypes = [POINTER(Py_avr_wrap), c_char_p, POINTER(c_uint32)]
sim_dll.get_data_at_label.restype = POINTER(c_ubyte)

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
    addr, size = sim.get_data_at_label("a")
    addr = cast(addr, POINTER(c_uint16))
    print(hex(addr[0]))
    print(size)
    del sim
