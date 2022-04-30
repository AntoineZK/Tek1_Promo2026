##
## EPITECH PROJECT, 2022
## B-MAT-100-NCY-1-1-105torus-antoine.khalidy
## File description:
## secant
##

import sys
import math
from utils import *

def secant(precision, a4, a3, a2, a1, a0):
    n = precision
    a = 0
    b = 1

    while (abs(a - b) > (10**(-precision))):
        result = b - ((b - a) / (quartic_function(b, a4, a3, a2, a1, a0) - 
                            quartic_function(a, a4, a3, a2, a1, a0))) * \
                                quartic_function(b, a4, a3, a2, a1, a0)
        a = b
        b = result
        if (10 **n) * result % 1 == 0:
            print("x =", result)
        else:
            print("x = %.*f" % (n, result))
