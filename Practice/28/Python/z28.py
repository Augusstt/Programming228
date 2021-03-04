n = int(input())
def print_factorization(n: int) -> None:
    i = 2
    while(n > 1):
        k = 0
        while(n % i == 0):
            k = k+1
            n = n / i
        if (k > 0):
            print(i)
            if (k > 1 ):
                print('^', k)
            if (n > 1):
                print('*')
        i = i+1
print_factorization(n)
