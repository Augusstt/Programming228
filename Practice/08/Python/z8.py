print("Вырожение (через пробел)")
x,f,y = input().split(' ')
x = int(x)
y = int(y)
if f == "/":
    x = x/y
    print("Ответ: ",x)
elif f == "*":
    x = x*y
    print("Ответ: ",x)
elif f == "+":
    x = x+y
    print("Ответ: ",x)
elif f == "-":
    x = x-y
    print("Ответ: ",x)
else:
    print("Невернный ввод")