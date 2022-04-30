##
## EPITECH PROJECT, 2022
## B-MAT-100-NCY-1-1-105torus-antoine.khalidy
## File description:
## bisection
##

import sys
import math
from utils import *

def bisection(precision, a4, a3, a2, a1, a0):
    a  = 0
    b  = 1
    afourth = quartic_function(a, a4, a3, a2, a1, a0)
    result  = 0
    s  = 1
    n = precision
    while abs(result - s) > (10**(-precision)):
        s = result
        result = (a + b)/ 2
        if afourth * quartic_function(result, a4, a3, a2, a1, a0) < 0:
            b = result
        else:
            a = result
        if (10**n) * result % 1 == 0:
            print("x =", result)
        else:
            print("x = %.*f" % (n, result))