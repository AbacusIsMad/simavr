from loader import *
import unittest
import json #for manual ed testcases
import os, sys, select #for dup and friends
#TODO actually redirect stdout

class JSB():
	def __init__(self):
		self.res = dict()
	def update(self, **kwargs):
		self.res.update(locals()['kwargs'])

class Sim_Test(unittest.TestCase):
	sim = None
	res_json = None

	@classmethod
	def setUpClass(cls):
		cls.sim = Simulator("./main.elf")
		cls.res_json = []

	@classmethod
	def tearDownClass(cls):
		del cls.sim
		res = {"testcases" : cls.res_json}
		print(json.dumps(res))
	
	def get_data_wrapper(self, label: str):
		return Sim_Unittest.sim.get_data_at_label(label)
	
	def ttest_gen_label(self, label, exp_vals, exp_size):
		tc = dict()
		tc["name"] = "the label \"{}\"".format(label)
		try:
			addr, size = self.get_data_wrapper(label)
			addr_vals = addr[0:size]
			if exp_vals == addr_vals and exp_size == size:
				tc["passed"] = True
				tc["feedback"] = "the label \"{}\" matched.".format(label)
			else:
				tc["passed"] = False
				tc["feedback"] = "the label \"{}\" did not match.".format(label)
				tc["expected"] = "vals: {}, size: {}".format(exp_vals, exp_size)
				tc["observed"] = "vals: {}, size: {}".format(addr_vals, size)
		except:
			tc["okay"] = False
			tc["feedback"] = "the label \"{}\" did not exist".format(label)
		finally:
			Sim_Unittest.res_json.append(tc)
	
	def setUp(self):
		self.tc = JSB()
	def tearDown(self):
		type(self).res_json.append(self.tc.res)
	
	def update(self, **kwargs):
		self.tc.update(**kwargs)
	
	def test_function_return(self):
		self.update(name="function returned")
		res = type(self).sim.test_func_all("woah", [0, 0], 20)
		self.update(passed = (res == 0), feedback = "function returned" if res == 0 else "the function either did not return or took too long (limit for this test is {} instructions)".format(20))
	
	def test_function_stack_pos(self):
		self.update(name="stack is restored correctly")
		sram = type(self).sim.get_data_at_addr(type(self).sim.sim, 0)
		s = sram[32 + 0x3d] | (sram[32 + 0x3e] << 8)
		sp, sp_next, sp_cur = [s], [s], [0]
		def get_sp(obj):
			#print(hex(sram[32 + 0x3d]), ' ', hex(sram[32 + 0x3e]))
			sp[0] = sp_next[0] #we want the second last sp
			sp_next[0] = sram[32 + 0x3d] | (sram[32 + 0x3e] << 8) 
			return 0
		def after_validate(obj):
			sp_cur[0] = sram[32 + 0x3d] | (sram[32 + 0x3e] << 8)
			return 0
		res = type(self).sim.test_func_all("woah", [0, 0], 20, prologue_validate=get_sp, after_validate=after_validate)
		if res != 0 or sp[0] != sp_cur[0]:
			self.update(passed=False, feedback="the stack was incorrectly restored (before call: <{}>, after: <{}>)".format(hex(sp[0]), hex(sp_cur[0])))
		else:
			self.update(passed=True, feedback="the stack was correctly restored")
	
	def test_function_register_restored(self):
		self.update(name="registers are saved")
		sram = type(self).sim.get_data_at_addr(type(self).sim.sim, 0)
		regs = np.array(sram[0:32], dtype=np.uint8) #save a copy
		fail = [False]
		offenders = []
		def after_validate(obj):
			regs_after = np.array(sram[0:32], dtype=np.uint8)
			ignore = 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 30, 31
			for i in range(32):
				if i in ignore:
					continue
				if regs[i] != regs_after[i]:
					fail[0] = True
					offenders.append(i)	
			return 0
		res = type(self).sim.test_func_all("woah", [0, 0], 20, after_validate=after_validate)
		if res != 0 or fail[0]:
			self.update(passed=False, feedback="the registers were not saved properly. offenders(register numbers)={}".format(offenders))
		else:
			self.update(passed=True, feedback="the registers were restored")
		
	
	def test_value(self):
		self.update(name="function adds")
		#method 1: watch sram for return location
		sram = type(self).sim.get_data_at_addr(type(self).sim.sim, 0)
		def after_validate(obj):
			return 1 if sram[24] != 30 else 0
		res = type(self).sim.test_func_all("woah", [10, 20], 20, after_validate=after_validate)
		if res != 0:
			self.update(passed=False, feedback="incorrect result. expected 30")
		else:
			self.update(passed=True)
		
	def test_overflow(self):
		self.update(name="function handles int overflow")
		#method 2: let it run and watch label
		#res = type(self).sim.test_func_all("woah", [255, 2], 20, epilogue_validate=e)
		res = type(self).sim.test_func_all("woah", [255, 2], 20)
		addr, size = type(self).sim.get_data_at_label("a")
		if res != 0 or cast(addr, POINTER(c_uint16))[0] != 1:
			self.update(passed=False, feedback="incorrect result. expected 1")
		else:
			self.update(passed=True)
		

if __name__ == "__main__":
	unittest.main()

