import random 

def guess(x):
    random_number = random.randint(1, x) #Selectionne un nombre aléatoire
    guess = 0
    tent = 7 #tentative restante
    while guess != random_number and tent>0: #Boucle tant que la proposition est fausse et qu'il reste des tentative
        guess = int(input(f'Guess a number between 1 and {x}:'))
        tent = tent -1
        if guess < random_number:
            print(f'Sorry, guess again. Too low. (Remaining test {tent} )')
        elif guess > random_number:
            print(f'Sorry, guess again. Too high (Remaining test {tent} )')
            
    #Affiche resultat
    if tent == 0:
        print(f'YOU LOSE, {random_number} was the number, try again')
    else :
        print(f'GG MY MAN YOU GOT IT, {random_number} WAS THE NUMBER')


guess(10)

def computer_guess(x):
    low = 1
    high = x
    feedback = ''
    while feedback != 'c':
        if low != high:
            guess = random.randint(low, high)
        else :
            guess = low
        guess = random.randint(low, high)
        feedback = input(f'Is {guess} too high (H), too low (L), or correct (C) ??: ').lower()
        if feedback == 'h':
            high = guess - 1
        if feedback == 'l':
            low = guess + 1
    
    print(f'GG MY PC BOY, YOU GOT IT, {guess} WAS THE NUMBER')

computer_guess(1000)

