def inv(x):
    if x != 0:
        a= "1/"
        b= str(x)
        print(f'{a}{b}')
    else:
        c = int(input('on divise pas par 0, entrez un autre nombre: '))
        if c != 0:
            a= "1/"
            b= str(c)
            print(f'{a}{c}')
        else:
            print('Tu force là')