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
    
    def inline(self):
        format = ""
        for i in range(len(self.value)):
            for j in range(len(self.value[0])):
                format += str(self.value[i][j])
                if not(i == len(self.value) - 1 and j == len(self.value[0]) - 1):
                    format += " "
        return format
    
    def reverse(self):
        if (len(self.value) != len(self.value[0])):
            return
        base_matrix = Matrix(concat_identite(self.value))
        base_matrix = Matrix(pivot_lignes(base_matrix.value))
        base_matrix = Matrix(pivot_lignes_rebours(base_matrix.value))
        return Matrix(extract_inverse(base_matrix.value))
        
    def __repr__(self):
        format = ""
        temp_value = 0
        for i in range(len(self.value)):
            for j in range(len(self.value[0])):
                temp_value = self.value[i][j]
                maximum = max_of_column(self, j)
                if (type(temp_value) == int):
                    format += "{:}".format(temp_value)
                else:
                    format += str(round(temp_value, 3))
                if (j != len(self.value[0]) - 1):
                    for _ in range(maximum - len("{:}".format(temp_value))):
                        format += " "
                    if (self.value[i][j + 1] < 0):
                        format += " "
                    format += "  "
            if i + 1 < len(self.value):
                format += '\n'
        return format
    

def generate_base_matrix(size):
    base_matrix = []
    for i in range(size):
        base_matrix.append([])
        for j in range(size):
            if (i == j):
                base_matrix[i].append(1)
            else:
                base_matrix[i].append(0)
    return Matrix(base_matrix)


def ascii_to_matrix(text, column=-1):
    if column == -1:
        size = round(sqrt(len(text)))**2
    else:
        size = ceil(len(text)/column) * column
    j = -1
    matrix = []
    for i in range(size):
        if column == -1:
            if i % sqrt(size) == 0:
                matrix.append([])
                j += 1
        else:
            if i % column == 0:
                matrix.append([])
                j += 1
        if i < len(text):
            ascii = ord(text[i])
        else:
            ascii = 0
        matrix[j].append(ascii)
    return (Matrix(matrix))

def matrix_to_ascii(matrix):
    ascii = ""
    for i in range(len(matrix.value)):
        for j in range(len(matrix.value[0])):
            if int(round(matrix.value[i][j])) != 0:
                ascii += chr(int(round(matrix.value[i][j])))
    return ascii

def inline_to_matrix(list, column=-1):
    if column == -1:
        size = round(sqrt(len(list)))**2
    else:
        size = ceil(len(list)/column) * column
    j = -1
    matrix = []
    for i in range(size):
        if column == -1:
            if i % sqrt(size) == 0:
                matrix.append([])
                j += 1
        else:
            if i % column == 0:
                matrix.append([])
                j += 1
        matrix[j].append(int(list[i]))
    return (Matrix(matrix))
        
        
def max_of_column(matrix, column):
    max = float('-inf')
    for i in range(len(matrix.value)):
        if (type(matrix.value[i][column]) == int):
            if max < len("{:}".format(matrix.value[i][column])):
                max = len("{:}".format(matrix.value[i][column]))
        else:
            if max < len(str(round(matrix.value[i][column], 3))):
                max = len(str(round(matrix.value[i][column], 3)))     
    return max

def pivot_lignes(M):
    for i in range(len(M)):
        j = recherche_pivot_lignes(M, i)
        if j != i:
            echange_lignes(M, i, j)
        if M[i][i] != 0:
            for j in range(i + 1, len(M)):
                transvection_ligne(M, j, i, -M[j][i] / M[i][i])
    return M

def recherche_pivot_lignes(M, i):
    m = abs(M[i][i])
    j = i
    for k in range(i + 1, len(M)):
        if abs(M[i][j]) > m:
            j = k
    return j

def transvection_ligne(M, i, j, l):
    M[i] = [M[i][k] + l * M[j][k] for k in range(len(M[i]))]
    return M

def echange_lignes(M, i, j):
    M[i], M[j] = M[j], M[i]
    return M

def pivot_lignes_rebours(M): 
    for i in reversed(range(len(M))):
        dilatation_ligne(M, i, 1 / M[i][i])
        for j in range(i):
            transvection_ligne(M, j, i, -M[j][i])
    return M

def dilatation_ligne(M, i, l):
    M[i] = [coeff * l for coeff in M[i]]
    return M

def extract_inverse(M):
    return [L[len(M):] for L in M]

def concat_identite(A):
    return [A[i] + [1 if j== i else 0 for j in range(len(A))] for i in range(len(A))]