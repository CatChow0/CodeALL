li = []

def start():
        act = int(input('Choisissez l\'option: Ajouter(1), Supprimer(2), Afficher(3), Vider(4), Quitter(5): '))
        
        if act == 1:
            add = input('Ajouter: ')
            li.append(add)
            start()
        if act == 2:
            rem = input('Retirer: ')
            li.remove(rem)
            start()
        if act == 3:
            print(li)
            start()
        if act == 4:
            li.clear()
            start()
        if act == 5:
            print('Sortie')
        if act == 0:
            print('Entrer une options valides')
            start()
        if act >5:
            print('Entrer une options valides')
            start()
start()