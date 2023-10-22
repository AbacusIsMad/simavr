from __future__ import annotations
from ctypes import *
import os
from collections.abc import Iterable
from typing import Callable
import numpy as np

avr_cycle_count_t = c_uint64
avr_flashaddr_t = c_uint32

def s2b(s: str):
	return bytes(s, encoding="utf-8")

class Avr_symbol(Structure):
	_fields_ = [
		("addr", c_uint32),
		("size", c_uint32),
		("symbol", c_char_p),
	]

class Py_avr_wrap(Structure):
	"""
	def get_symbol(self, symbol: str):
		res = sim_dll.get_symbol(byref(self), s2b(symbol))
		#handle null ptr
		if not res:
			return None
		return res.contents
	
	def get_data_at_label(self, label: str):
		res_size = c_uint32(0)
		addr = sim_dll.get_data_at_label(byref(self), s2b(label), byref(res_size))
		if not addr:
			addr = None
		return addr, res_size.value
	
	def test_func_all(self, label: str, args: Iterable, inst_limit: int, prologue_validate: v_prototype = None, running_validate: v_prototype = None, after_validate: v_prototype = None, epilogue_validate: v_prototype = None):
		begin = "AVRBIND_{}_BEGIN".format(label)
		end = "AVRBIND_{}_END".format(label)
		if (not self.get_symbol(begin)) or (not self.get_symbol(end)):
			raise ValueError("cannot find labels '{}' and '{}'".format(begin, end))
		#transform args to c pointer using numpy
		arg_arr = np.array(args, dtype=np.uint8)
		arg_ptr = arg_arr.ctypes.data_as(POINTER(c_uint8))
		return sim_dll.supervise_func_all(byref(self), s2b(label), s2b(begin), s2b(end), arg_ptr, len(arg_arr), inst_limit, py_validate(prologue_validate), py_validate(running_validate), py_validate(after_validate), py_validate(epilogue_validate))
	
	def reset(self, do_startup: bool = True):
		sim_dll.py_sim_reset(byref(self), do_startup)

	def __del__(self):
		sim_dll.py_sim_terminate(byref(self))
	"""

#forward declaration
Py_avr_wrap.v_prototype = Callable[[POINTER(Py_avr_wrap)], int]
Py_avr_wrap._fields_ = [
		("avr", c_void_p),
		("stop_addr", c_uint32),
		("symbolcount", c_uint32),
		("symbol_addr_sorted", POINTER(POINTER(Avr_symbol))),
		("symbol_name_sorted", POINTER(POINTER(Avr_symbol))),
		("get_data", CFUNCTYPE(POINTER(c_uint8), POINTER(Py_avr_wrap))),
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
sim_dll.get_data_at_addr.argtypes = [POINTER(Py_avr_wrap), c_uint16]
sim_dll.get_data_at_addr.restype = POINTER(c_ubyte)
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
#I need to keep a track of this according to ctypes doc
py_validate = CFUNCTYPE(c_int, POINTER(Py_avr_wrap))
sim_dll.supervise_func_call.argtypes = [
	POINTER(Py_avr_wrap),
	c_char_p,
	c_char_p,
	POINTER(c_uint8),
	c_uint8,
	c_int,
	py_validate,
	py_validate,
]
sim_dll.supervise_func_call.restype = POINTER(Avr_save)
sim_dll.supervise_func_finalise.argtypes = [
	POINTER(Py_avr_wrap),
	POINTER(Avr_save),
	c_char_p,
	c_bool,
	py_validate,
]
sim_dll.supervise_func_finalise.restype = c_int
sim_dll.supervise_func_all.argtypes = [
	POINTER(Py_avr_wrap),
	c_char_p,
	c_char_p,
	c_char_p,
	POINTER(c_uint8),
	c_uint8,
	c_int,
	py_validate,
	py_validate,
	py_validate,
	py_validate,
]
sim_dll.supervise_func_all.restype = c_int
sim_dll.jump_to.argtypes = [POINTER(Py_avr_wrap), avr_flashaddr_t]
sim_dll.jump_to.restype = c_int
sim_dll.run_until.argtypes = [POINTER(Py_avr_wrap), avr_flashaddr_t, c_uint32, py_validate]
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
		self.sim = sim_dll.py_sim_init(s2b(exe_path), s2b(mmcu), do_startup)

	#this returns the actual object for ease of use
	def get_symbol(self, symbol: str):
		res = sim_dll.get_symbol(self.sim, s2b(symbol))
		#handle null ptr
		if not res:
			return None
		return res.contents

	def get_data_at_label(self, label: str):
		res_size = c_uint32(0)
		addr = sim_dll.get_data_at_label(self.sim, s2b(label), byref(res_size))
		if not addr:
			addr = None
		return addr, res_size.value		
	@classmethod
	def get_data_at_addr(cls, obj: POINTER(Py_avr_wrap), addr: int):
		return sim_dll.get_data_at_addr(obj, addr);

	v_prototype = Callable[[POINTER(Py_avr_wrap)], int]
	def test_func_all(self, label: str, args: Iterable, inst_limit: int, prologue_validate: v_prototype = None, running_validate: v_prototype = None, after_validate: v_prototype = None, epilogue_validate: v_prototype = None):
		begin = "AVRBIND_{}_BEGIN".format(label)
		end = "AVRBIND_{}_END".format(label)
		if (not self.get_symbol(begin)) or (not self.get_symbol(end)):
			raise ValueError("cannot find labels '{}' and '{}'".format(begin, end))
		#transform args to c pointer using numpy
		arg_arr = np.array(args, dtype=np.uint8)
		arg_ptr = arg_arr.ctypes.data_as(POINTER(c_uint8))
		#convert None to NULL cos python can't handle it
		p = py_validate() if prologue_validate is None else py_validate(prologue_validate)
		r = py_validate() if running_validate is None else py_validate(running_validate)
		a = py_validate() if after_validate is None else py_validate(after_validate)
		e = py_validate() if epilogue_validate is None else py_validate(epilogue_validate)
		
		return sim_dll.supervise_func_all(self.sim, s2b(label), s2b(begin), s2b(end), arg_ptr, len(arg_arr), inst_limit, p, r, a, e)

	def reset(self, do_startup: bool = True):
		sim_dll.py_sim_reset(self.sim, do_startup)

	def __del__(self):
		sim_dll.py_sim_terminate(self.sim)

def create_simulation(exe_path: str, mmcu: str = "atmega328p", do_startup: bool = True):
	if not os.path.isfile(exe_path):
		raise FileNotFoundError("cannot find '{}'".format(exe_path))
	return sim_dll.py_sim_init(s2b(exe_path), s2b(mmcu), do_startup).contents #the whole struct

if __name__ == "__main__":
	sim = Simulator("./main.elf")
	#sim = create_simulation("./main.elf")
	"""
	addr, size = sim.get_data_at_label("a")
	addr = cast(addr, POINTER(c_uint16))
	print(hex(addr[0]))
	print(size)
	"""
	
	def p(obj):
		print("prologue")
		return 0
	def r(obj):
		print("running")
		return 0
	def e(obj):
		print("epilogue")
		return 0
	data = [10, 20]
	def after_validate(obj: POINTER(Py_avr_wrap)):
		data_ptr = sim.get_data_at_addr(obj, 0)
		res = 0 if np.uint8(data[0] + data[1]) == data_ptr[24] else 1
		return res
	
	
	res = sim.test_func_all("woah", data, 20, after_validate = after_validate)
	print("result:", res)
	
	del sim
