from loader import *
import unittest
import json #for manual ed testcases
import os, sys, select #for dup and friends
#TODO actually redirect stdout

class Sim_Unittest(unittest.TestCase):
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
        tc["true"] = False
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
        finally:
            Sim_Unittest.res_json.append(tc)
    
    def test_a(self):
        self.ttest_gen_label("a", [1, 2], 2);
    
    def test_b(self):
        self.ttest_gen_label("b", [3, 4, 5, 6, 7, 8, 9], 7)
    
    def test_empty(self):
        self.ttest_gen_label("empty", [0] * 10, 10)
    
    def test_string(self):
        self.ttest_gen_label("my_string", [ord(c) for c in "hello world!\0"], 13)

if __name__ == "__main__":
    unittest.main()

