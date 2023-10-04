def pyramide(n):
    etoile = '*'
    print(' ' * (n+1) + etoile)
    for x in range(n):
        etoile += '**'
        print(' ' * (n-x) + etoile)