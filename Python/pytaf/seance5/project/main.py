from colorama import Fore
from colorama import Style
from io import open

def tri_selection(crepe_def):
    for i in range(len(crepe_def)):
        min = i
        for j in range(i+1, len(crepe_def)):
            if crepe_def[min]> crepe_def[j]:
                min = j
        tmp = crepe_def[i]
        crepe_def[i] = crepe_def[min]
        crepe_def[min] = tmp
    return crepe_def

def tri_bulle(Price):
    n = len(Price)
    for i in range(n):
        for j in range(0, n-i-1):
            if Price[j] > Price[j+1] :
                Price[j], Price[j+1] = Price[j+1], Price[j]

def tri_prix():
    for i in range (len(Price)):
        x = Price[i]
        x = str(x)
        k = 0
        while x not in crepe_def[k]:
            k = k+1
        y = crepe_def[k]
        Chocapic.append(y)              
            

def choice(): 
    end_of_choice = False
    while end_of_choice == False:
        for i in range (len(ING)):
            print(f'{i+1}'+'. '+f'{ING[i]}')
        Choice = int(input('Choisissez le numero de l\'ingrédient à ajouter : '))
        choix.append(ING[Choice-1])
        verif = int(input('Voulez-vous autre chose, Oui(1) Non(2): '))
        if verif == 2:
            end_of_choice = True
    final_choice = str(input(f'Es-ce bien votre selection {Fore.LIGHTMAGENTA_EX}{choix}{Style.RESET_ALL} ? Oui(o) Non(n): '))
    if final_choice == 'n':
        choix.clear()
        choice()
    if final_choice == 'o':
        return
               
rank = [1,2,3,4,5,6,7]
crepe_def = [f'Crêpe Confiture Fraise - {Fore.YELLOW}5.90 €{Style.RESET_ALL} - {Fore.MAGENTA}Sucrée{Style.RESET_ALL}\nSucre Glace, Confiture fraise',f'Crêpe Nutela - {Fore.YELLOW}6.90 €{Style.RESET_ALL} - {Fore.MAGENTA}Sucrée{Style.RESET_ALL}\nNutela, Chantilly',f'Crêpe Sarasin au trois fromage - {Fore.YELLOW}7.90 €{Style.RESET_ALL} - {Fore.GREEN}Végétarienne{Style.RESET_ALL}\nFromage de chèvre, mozzarella, cheddar',f'Crêpe Jambon Fromage - {Fore.YELLOW}9.90 €{Style.RESET_ALL} - {Fore.LIGHTBLACK_EX}Salée{Style.RESET_ALL}\n Jambon, Ananas, Fromage',f'Crêpe Kebab Poulet - {Fore.YELLOW}8.90 €{Style.RESET_ALL} - {Fore.LIGHTBLACK_EX}Salée{Style.RESET_ALL}\n Kebab, Poulet, Tomate, Émentale',f'Crêpe du Jour - {Fore.YELLOW}5.19 €{Style.RESET_ALL} - {Fore.MAGENTA}Sucrée{Style.RESET_ALL}\n Ananas Noisette Saucissons','Crêpe personalisée']
Liste_menu = [f'Afficher la liste de crêpes par {Fore.CYAN}ordre alphabetique{Style.RESET_ALL}', f'Afficher la liste de crêpes par {Fore.YELLOW}prix croissant{Style.RESET_ALL}', f'{Fore.RED}Crêpe la plus chère{Style.RESET_ALL}', f'{Fore.GREEN}Crêpe la moins chère{Style.RESET_ALL}']
Price = [5.90,6.90,7.90,9.90,8.90,5.19]
Chocapic = []
ING = ['Nutela', 'Confiture Fraise', 'Ananas', 'Noisette','Jambon','Fromage','Kebab','Poulet','Sarasin au trois fromage','Tomate','Chantilly','Sucre Glace','Saucissons']
choix = []
stock_menu = ['Crêpe Confiture Fraise - 5.90 € - Sucrée\n Sucre Glace, Confiture fraise','Crêpe Nutela - 6.90 € - Sucrée\n Nutela, Chantilly','Crêpe Sarasin au trois fromage - 7.90 € - Végétarienne\n Fromage de chèvre, mozzarella, cheddar','Crêpe Jambon Fromage - 9.90 € - Salée\n Jambon, Ananas, Fromage','Crêpe Kebab Poulet - 8.90 € - Salée\n Kebab, Poulet, Tomate, Émentale','Crêpe du Jour - 5.19 € - Sucrée\n Ananas Noisette Saucissons']

with open('list.txt', 'w', encoding='utf-8') as r:
    for item in stock_menu:
        r.write(f'{item}'+'\n')

with open('list.txt', 'a', encoding='utf-8') as h:
    for item in Price:
        h.write(f'{item}'+'€'+'\n')

for i in range (4):
    print(f'{rank[i]}'+'. '+ f'{Liste_menu[i]}') 
menu = int(input('Choisissez une option: '))
if menu == 1 :
    tri_selection(crepe_def)
    for i in range(len(crepe_def)):
        print(f'{rank[i]}'+'. '+ f'{crepe_def[i]}')
    meh = int(input(f'\n{Fore.BLUE}Que souhaitez-vous? : {Style.RESET_ALL}'))
    if meh < rank[-1]:
        print(f'{Fore.GREEN}Votre Commande{Style.RESET_ALL}({crepe_def[meh]}){Fore.GREEN} a été enregistré, nous vous prions de bien vouloir payer.{Style.RESET_ALL}')
    if meh == rank[-1]:
        choice()
        p = 6 + len(choix)
        print(f'Votre Crêpe {Fore.LIGHTMAGENTA_EX}{choix}{Style.RESET_ALL} est en train d\'être préparer, le prix est de {Fore.YELLOW}{p} €{Style.RESET_ALL} ,{Fore.GREEN}buon{Style.RESET_ALL} appe{Fore.LIGHTRED_EX}tito{Style.RESET_ALL}')               
        with open('list.txt','a',encoding='utf-8') as ch:
            ch.write('Crêpe personalisé : \n')
            for item in choix:
                ch.write(f'{item}'+'\n')
if menu == 2 :
    tri_bulle(Price)
    tri_prix()
    for i in range(len(Chocapic)):
        print(f'{rank[i]}'+'. '+f'{Chocapic[i]}')
    print(f'{rank[-1]}'+'. '+f'{crepe_def[-1]}')
    meh = int(input(f'\n{Fore.BLUE}Que souhaitez-vous? : {Style.RESET_ALL}'))
    if meh < rank[-1]:
        print(f'{Fore.GREEN}Votre Commande{Style.RESET_ALL}({Chocapic[meh-1]}){Fore.GREEN} a été enregistré, nous vous prions de bien vouloir payer.{Style.RESET_ALL}')
    if meh == rank[-1]:
        choice()
        p = 6 + len(choix)
        print(f'Votre Crêpe {Fore.LIGHTMAGENTA_EX}{choix}{Style.RESET_ALL} est en train d\'être préparer, le prix est de {Fore.YELLOW}{p} €{Style.RESET_ALL} ,{Fore.GREEN}buon{Style.RESET_ALL} appe{Fore.LIGHTRED_EX}tito{Style.RESET_ALL}') 
        with open('list.txt','a',encoding='utf-8') as ch:
            ch.write('Crêpe personalisé : \n')
            for item in choix:
                ch.write(f'{item}'+'\n')
if menu == 3 :
    tri_bulle(Price)
    tri_prix()
    print('La crêpe la plus chère est la\n '+f'{Chocapic[-1]}')
if menu == 4 :
    tri_bulle(Price)
    tri_prix()
    print('La crêpe la moins chère est la\n '+f'{Chocapic[0]}')
if menu >4 or menu <1 :
    print(f"{Fore.LIGHTRED_EX}MERCI DE SELECTIONER UNE OPTION VALIDE{Style.RESET_ALL}")
