##
## EPITECH PROJECT, 2022
## B-MAT-100-NCY-1-1-105torus-antoine.khalidy
## File description:
## utils
##

import sys
import math

def quartic_function(x, a4, a3, a2, a1, a0):
    result = (a4 * (x**4) + a3 * (x**3) + a2 * (x**2) + a1 * x  + a0)
    return (result)

def derivation(x, a4, a3, a2, a1):
    result = (4 * a4 * (x**3) + 3 * a3 * (x**2) + 2 * a2 * x + a1)
    return (result)
