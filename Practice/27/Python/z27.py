n = int(input())
a = list(map(int, input().split()))
b, c = [], []
j = 0
 
while j < n:
    j += 1
    if j < 5:
        c.append(a[0:j]) 
    elif j == 5:
        c.append(a[0:j])
        b.extend(a[0:j])
    else:
        if a[j-1] < max(b):
            b[b.index(max(b))] = a[j-1]
        temp = tuple(b)
        c.append(list(temp))
        del temp
 
for i in c:
    i.sort()
    i.reverse()
    i = map(str, i)
    print(" ".join(i))

