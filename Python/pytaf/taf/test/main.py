from colorama import Fore
from colorama import Style
SUC = ['Crêpe Nutela','Crêpe Confiture Fraise', 'Crêpe Ananas Noisette']
SAL = ['Crêpe Jambon Fromage', 'Crêpe Kebab Poulet']
VEG = ['Crêpe Sarasin au trois fromage']
ING = ['Nutela', 'Confiture Fraise', 'Ananas', 'Noisette','Jambon','Fromage','Kebab','Poulet','Sarasin au trois fromage','Tomate','Chantilly','Sucre Glace',]
Perso = []
Choice = int(input('Que voulez-vous faire Regarder le menu(1), Crêpe personaliser(2) ?: '))
price = [4,0.6,0.5,0.7,0.6,0.3,0.5,1.6,1.3,1.8,0.9,0.2,2.8]
Com = []

def choice():
    if Choice == 1 :
        print('\n',)
    if Choice == 2 :
        print('\n',', '.join(ING))
        end_of_choice = False
        while end_of_choice == False:
            Pimp = str(input('Quel ingredient souhaitez-vous? : '))
            Perso.append(Pimp)
            pimp_plus = str(input('Voulez-vous autre chose? oui(o), non(n): '))
            if pimp_plus == 'n':
                end_of_choice = True
        final_choice = str(input(f'Es-ce bien les ingredient que vous souhaitez?\n{Perso}\n OUI(o), NON(n) :  '))
        if final_choice == 'n':
            Perso.clear()
            choice()
        for mot in ING:
            if mot in Perso:
                Com.append(mot)
        print(Com)
        Pos = ING.index()
        print(Pos)
        
        


choice()
   
if Choice == 0 or Choice >2:
        print(f'{Fore.LIGHTRED_EX}Choisissez une option valide{Style.RESET_ALL}')