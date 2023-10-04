import random

operateur = ['+', '-', '*', '/']
# Selectionne un operateur aléatoirement
def selectoperateur(operateur):
    return random.choice(operateur)

def play(x):
    
    tent = 5 #Nombre de tentative restant
    score = 0 
    while tent>0:
    
        random_calcP = random.randint(1, x) #Premier nombre aléatoire pour le calcul
        random_calcS = random.randint(1, x) #Second nombre aléatoire
        ope = selectoperateur(operateur)
        result = input(f'WHAT IS THE RESULT FOR --> {random_calcP} {ope} {random_calcS}: ') #Affiche le calcul

        tent = tent -1 #retire une tentative

        # verifie les calcules
        if ope == '+':
            calc = random_calcP + random_calcS
            if calc == float(result) :
                print(f'GOOD JOB {calc} WAS THE RESULT')
                score = score +1
            else :
                print(f'NOPE {result} WASN\'T THE CORRECT ANSWER? {calc} WAS THE CORRECT ONE ')
        if ope == '-':
            calc = random_calcP - random_calcS
            if calc == float(result) :
                print(f'GOOD JOB {calc} WAS THE RESULT')
                score = score +1
            else :
                print(f'NOPE {result} WASN\'T THE CORRECT ANSWER? {calc} WAS THE CORRECT ONE ')
        if ope == '*':
            calc = random_calcP * random_calcS
            if calc == float(result) :
                print(f'GOOD JOB {calc} WAS THE RESULT')
                score = score +1
            else :
                print(f'NOPE {result} WASN\'T THE CORRECT ANSWER? {calc} WAS THE CORRECT ONE ')
        if ope == '/':
            calc = random_calcP / random_calcS
            if calc == float(result) :
                print(f'GOOD JOB {calc} WAS THE RESULT')
                score = score +1
            else :
                print(f'NOPE {result} WASN\'T THE CORRECT ANSWER? {calc} WAS THE CORRECT ONE ')
                
    # Affiche le score
    if tent == 0 and score == 5:
        print(f'GG MY MAN YOU\'V GOT {score}/5 ')
    if tent == 0 and score == 0:
        print(f'GO BACK TO SCOOL YOU\'V GOT {score}/5 ')
    if tent == 0 and score>0 and score<5:
        print(f'NICE TRY YOU\'V GOT {score}/5 ')
        

play(5)