import unittest
from test2 import fun2

def fun(x):
    return x + 1

class MyTest(unittest.TestCase):
    def test(self):
        self.assertEqual(fun(3), 4)
        self.assertEqual(fun2(3),5)
    def test2(self):
        self.assertEqual(fun2(3),5)

