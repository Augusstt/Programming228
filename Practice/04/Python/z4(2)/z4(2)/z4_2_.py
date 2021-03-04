print ('Введите x0, v0, t')
x0, v0, t = map(float,input().split())
a = 9.8
x = x0+v0*t-a*t*t/2
r = abs(x - x0)
print (r)