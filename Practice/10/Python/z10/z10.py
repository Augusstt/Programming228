s, l1, l2, r1, r2 = input().split()
if l1 < r1:
		x1 = l1
else:
		x1 = r1
if int(x1) + int(l2) == int(s):
		print(x1,l2)
elif int(x1) + int(r2) == int(s):
		print(x1,r2)
else:
	    print(-1)
