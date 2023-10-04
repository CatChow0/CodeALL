etal_inch = 2.54 #cm (Valeur étalon d'un pouce en centimètre)
etal_cm = 0.394 #inch (Valeur étalon d'un centimètre en pouce)
type = input('Inch --> Cm (1), Cm --> Inch (2): ')
if type == 1:
    A = input('Convert Inch --> Cm, please enter value: ')
    B = A 
    A = float(A) * float(etal_cm)
    print(f'{B}inch = {A}cm')
else:
    A = input('Convert Cm --> Inch, please enter value: ')
    B = A
    A = float(A) * float(etal_inch)
    print(f'{B}Cm = {A}Inch')