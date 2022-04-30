from math import *

class Matrix:
    
    def __init__(self, value):
        self.value = value
        
    def multiply_by(self, matrix1):
        new_matrix = []
        for i in range(len(self.value)):
            line = []
            for j in range(len(matrix1.value[0])):
                element = 0
                for k in range(len(self.value[0])):
                    element += self.value[i][k] * matrix1.value[k][j]
                line.append(element)
            new_matrix.append(line)
        return Matrix(new_matrix)
    
    def __repr__(self):
        format = ""
        temp_value = 0
        for i in range(len(self.value)):
            for j in range(len(self.value[0])):
                temp_value = self.value[i][j]
                if "{:.2f}".format(temp_value) == "-0.00":
                    temp_value = 0
                format += "{:.2f}".format(temp_value)
                if temp_value >= 0 and j != len(self.value[0]) - 1:
                    format += "   "
                elif j != len(self.value[0]) - 1:
                    format += "  "
            if i + 1 < len(self.value):
                format += '\n'
        return format

def translation(i, j):
    print("Translation along vector ({0:.0f}, {1:.0f})".format(i, j))
    base_matrix = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    base_matrix.value[0][2] = i
    base_matrix.value[1][2] = j
    return (base_matrix)
    
    
def scaling(i, j):
    print("Scaling by factors {0:.0f} and {1:.0f}".format(i, j))
    base_matrix = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    base_matrix.value[0][0] = i
    base_matrix.value[1][1] = j
    return (base_matrix)

def rotation(degree):
    print("Rotation by a {:.0f} degree angle".format(degree))
    base_matrix = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    degree = radians(degree)
    base_matrix.value[0][0] = cos(degree)
    base_matrix.value[0][1] = -sin(degree)
    base_matrix.value[1][0] = sin(degree)
    base_matrix.value[1][1] = cos(degree)
    return (base_matrix)

def reflection(degree):
    print("Reflection over an axis with an inclination angle of {:.0f} degrees".format(degree))
    degree = radians(degree)
    base_matrix = Matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    if degree != 0:
        base_matrix.value[0][0] = cos(2*degree)
    else:
        base_matrix.value[0][0] = 1
    base_matrix.value[0][1] = sin(2*degree)
    base_matrix.value[1][0] = sin(2*degree)
    if degree != 0:
        base_matrix.value[1][1] = -cos(2*degree)      
    else:
        base_matrix.value[1][1] = 1
    return (base_matrix)