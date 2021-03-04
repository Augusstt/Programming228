from random import randrange
import math

def BozoSort(array, t = True):
    sorted = False
    n = len(array)
    while not sorted:
    
        if(t):
            index1 = randrange(0, len(array))
            index2 = randrange(0, len(array))
            temp = array[index1]
            array[index1] = array[index2]
            array[index2] = temp
            sorted = True
            for i in range (1, n):
                if(array[i-1] > array[i]):
                    sorted = False
                    break
    
        else:
            index1 = randrange(0, len(array))
            index2 = randrange(0, len(array))
            temp = array[index1]
            array[index1] = array[index2]
            array[index2] = temp
            sorted = True
            for i in range (1, n):
                if(array[i-1] < array[i]):
                    sorted = False
                    break
    return array



print('Введите количество элементов')
n = int(input())
s = round(math.sqrt(n))
array = list(map(int, input().split()))
print()
array_2 = []
a = array[0]
b = array[1]
c = array[2]
array = BozoSort(array)
array_cop = array.copy()
array_2.append(array_cop)
print(" ".join(map(str, array)))
array = BozoSort(array, False)
array_2.append(array)
print(" ".join(map(str, array)))
print ("\n".join([" ".join(map(str,array_2[i])) for i in range(len(array_2))]))
print(" ".join(map(str, BozoSort([a, b, c]))))
print(" ".join(map(str, BozoSort([a, b, c], False))))
