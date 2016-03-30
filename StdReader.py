# import math
#-*- coding:UTF-8 -*-
class StdReader:
	def read_int(self):
		return int(self.read_string())

	def read_ints(self, sep=None):
		return [int(i) for i in self.read_strings(sep)]

	def read_float(self):
		return float(self.read_string())

	def read_floats(self, sep=None):
		return [float(i) for i in self.read_strings(sep)]

	def read_string(self):
		return input()

	def read_strings(self, sep=None):
		return self.read_string().split(sep)

reader = StdReader()
