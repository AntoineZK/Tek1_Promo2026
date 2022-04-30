##
## EPITECH PROJECT, 2022
## B-MAT-100-NCY-1-1-105torus-antoine.khalidy
## File description:
## newton
##

import sys
import math
from utils import *

def newton(precision, a4, a3, a2, a1, a0):
    result = 0.5
    c = 0
    analyse = 0
    n = precision

    while (abs(c - result) > 10**(-precision)):
        c = result
        analyse += 1
        if (10**n * result % 1) == 0:
            print("x =", result)
        else:
            print("x = %.*f" % (n, result))
        result -= ((quartic_function(result, a4, a3, a2, a1, a0) /
            derivation(result, a4, a3, a2, a1)))
        if (analyse > 15):
            print("Invalid number of calcul\n")
            exit (84)