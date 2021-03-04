def main():
 h1, m1 = map(int,input().split(":"))
 if h1<0 or h1 >= 24 or m1<0 or m1 >= 60:
     print("Неправильно. Введите ещё раз")
     return main()
 h2, m2 = map(int,input().split(":"))
 if h2<0 or h2 >= 24 or m2 >= 60 or m2<0:
     print("Введите ещё раз")
     return main()
 elif int(h2)-int(h1) == 0 and abs(int(m2)-int(m1)) <= 15:
    print("Встреча состоится")
 else :
    print("Встреча не состоится")
main()
