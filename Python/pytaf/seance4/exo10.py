import random
from progress.bar import IncrementalBar
from colorama import Fore
from colorama import Style
       
pv_pla = 50
pv_mob = 50
pot = 3
end_of_game = False

turn_txt = f'\n{Fore.GREEN}Début de votre tour.{Style.RESET_ALL}\n'
act_txt = f'\nSouhaitez-vous {Fore.RED}attaquer (1){Style.RESET_ALL} ou {Fore.MAGENTA}utiliser une potion (2){Style.RESET_ALL} ?:'

def value_hp_pla():
    with IncrementalBar(f'{Fore.GREEN}Vos pv   {Style.RESET_ALL}', max=50) as Bar:
        for i in range(pv_pla):
            Bar.next()

def value_hp_mob():
    with IncrementalBar(f'{Fore.LIGHTRED_EX}Pv Ennemi{Style.RESET_ALL}', max=50) as Bar:
        for i in range(pv_mob):
            Bar.next()

while end_of_game == False:

    print(turn_txt)
    print(value_hp_pla())
    print(value_hp_mob())
    act = int(input(act_txt))
    if act == 1:
        att_pla = random.randint(5,10)
        pv_mob = pv_mob - att_pla
        print(f'\n{Fore.LIGHTGREEN_EX}Vous{Style.RESET_ALL} avez infilgé {Fore.RED}{att_pla} dégât{Style.RESET_ALL}, les pv du monstre sont de {Fore.LIGHTRED_EX}{pv_mob}{Style.RESET_ALL}\n')
        if pv_mob >0:
            att_mob = random.randint(5,15)
            pv_pla = pv_pla - att_mob
            print(f'{Fore.LIGHTRED_EX}L\'ennemie{Style.RESET_ALL} vous a infligé {Fore.RED}{att_mob} dégât{Style.RESET_ALL}, vos pv sont de {Fore.GREEN}{pv_pla}{Style.RESET_ALL}' )
            if pv_pla <=0:
                end_of_game = True
        else:
            end_of_game = True
    if act == 2:
        if pot>0:
            pot_eff = random.randint(15,50)
            pv_pla = pv_pla + pot_eff
            pot = pot -1
            print(f'{Fore.LIGHTGREEN_EX}Vous {Style.RESET_ALL}avez utilisez une {Fore.LIGHTMAGENTA_EX}potion ({pot} restante){Style.RESET_ALL} et récuprer {Fore.GREEN}{pot_eff} pv{Style.RESET_ALL}')
            att_mob = random.randint(5,15)
            pv_pla = pv_pla - att_mob
            print(f'{Fore.LIGHTRED_EX}L\'ennemie{Style.RESET_ALL} vous a infligé {Fore.RED}{att_mob} dégât{Style.RESET_ALL}, vos pv sont de {Fore.GREEN}{pv_pla}{Style.RESET_ALL}' )
        if pot <=0:
            print(f'{Fore.LIGHTRED_EX}Tu n\'as plus de potion{Style.RESET_ALL}')
    if act == 0 or act >2:
        print(f'{Fore.LIGHTRED_EX}Choisissez une option valide{Style.RESET_ALL}')
if end_of_game == True and pv_pla >0:
    print(value_hp_pla())
    print(value_hp_mob())
    print(f'\n{Fore.LIGHTGREEN_EX}Bravo tu a gagner la partie{Style.RESET_ALL}\n')
else:
    print(value_hp_pla())
    print(value_hp_mob())
    print(f"\n{Fore.RED}Tu a perdu{Style.RESET_ALL}\n")
