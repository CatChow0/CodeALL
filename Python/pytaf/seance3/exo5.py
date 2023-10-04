import collections
def start():
    a = str(input('Ecrivez moi: '))
    a = a[::-1]
    print(a)
    a = a[::-1]
    nb_maj = 0
    for lettre in a:
        if lettre.lower() != lettre:
            nb_maj += 1
    if nb_maj>0:
        print("Il y a " + str(nb_maj) + " majuscules.")
        l = list(a.split(" "))
        l.sort(key=len)
        print(l)
        print(l[-1], "est le mot le plus long, et",l[0],"est le mot le plus petit")
        b = str(input('Autre chose: '))
        b = list(b.split(" "))
        
    else:
        print('Il faut au moins une majuscules')
        start()
        
start()