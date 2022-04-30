##
## EPITECH PROJECT, 2021
## B-MAT-100-NCY-1-1-104intersection-antoine.khalidy
## File description:
## sphere
##

import math

def sphere(pointx, pointy, pointz, vectorx, vectory, vectorz, radius):
    print ("Sphere of radius " +str(radius))
    print ("Line passing through the point ("+str(pointx)+",",str(pointy)+",",str(pointz)+") and parallel to the vector ("+str(vectorx)+","
           ,str(vectory)+",",str(vectorz)+")")

    vectorx_a = (vectorx) ** 2
    vectorx_b = (2 * vectorx * pointx)
    vectorx_c = (pointx) ** 2
    
    vectory_a = (vectory) ** 2
    vectory_b = (2 * vectory * pointy)
    vectory_c = (pointy) ** 2

    vectorz_a = (vectorz) ** 2
    vectorz_b = (2 * vectorz * pointz)
    vectorz_c = (pointz) ** 2

    a = vectorx_a + vectory_a + vectorz_a
    b = vectorx_b + vectory_b + vectorz_b
    c = vectorx_c + vectory_c + vectorz_c
    c = c - (radius) ** 2
    delta = (b) ** 2 - (4 * a * c)
    if (delta > 0):
        x1 = (float(-b) - float(math.sqrt(delta)))/(2 * float(a))
        x2 = (float(-b) + float(math.sqrt(delta)))/(2 * float(a))
        x = vectorx * x1 + pointx
        y = vectory * x1 + pointy
        z = vectorz * x1 + pointz
        u = vectorx * x2 + pointx
        v = vectory * x2 + pointy
        w = vectorz * x2 + pointz
        x3 = "{:.3f}".format(x)
        y3 = "{:.3f}".format(y)
        z3 = "{:.3f}".format(z)
        u3 = "{:.3f}".format(u)
        v3 = "{:.3f}".format(v)
        w3 = "{:.3f}".format(w)
        print ("2 intersection points:")
        print ("("+str(u3) + ", "+str(v3) + ", "+str(w3) + ")")
        print ("("+str(x3) + ", "+str(y3) + ", "+str(z3) + ")")
    elif (delta == 0):
        t = (-float(b))/(2 * float(a))
        x = vectorx * t + pointx
        y = vectory * t + pointy
        z = vectorz * t + pointz
        x3 = "{:.3f}".format(x)
        y3 = "{:.3f}".format(y)
        z3 = "{:.3f}".format(z)
        print ("1 intersection point:")
        print ("("+str(x3)+",",str(y3)+",",str(z3)+")")
    else:
        print ("No intersection point.")