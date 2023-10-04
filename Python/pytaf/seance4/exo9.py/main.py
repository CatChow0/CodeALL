from rich.prompt import Prompt
from rich.console import Console
from random import choice
from word import word_list

SQUARES = {
    'correct_place': '🟩',
    'correct_letter': '🟨',
    'incorrect_letter': '⬛'
}

start_message = f'\n[white on blue]ON VEUT TUSMO[/]\n'
instruction = "ESSAYE DE DEVINER\n"
tentative_en_cours = "\nEntrer le mot"
tentative = 6

def correct_place(letter):
    return f'[black on green]{letter}[/]'


def correct_letter(letter):
    return f'[black on yellow]{letter}[/]'


def incorrect_letter(letter):
    return f'[black on white]{letter}[/]'


def check_tent(tent, reponse):
    tenter = []
    tusmo_patern = []
    for i, letter in enumerate(tent):
        if reponse[i] == tent[i]:
            tenter += correct_place(letter)
            tusmo_patern.append(SQUARES['correct_place'])
        elif letter in reponse:
            tenter += correct_letter(letter)
            tusmo_patern.append(SQUARES['correct_letter'])
        else:
            tenter += incorrect_letter(letter)
            tusmo_patern.append(SQUARES['incorrect_letter'])
    return ''.join(tenter), ''.join(tusmo_patern)


def game(console, mot_choisie):
    fin_de_partie = False
    deja_trouver = []
    Tusmo_patern_complet = []
    mot_tenter_tout = []

    while not fin_de_partie:
        tent = Prompt.ask(tentative_en_cours).upper()
        while len(tent) != 7 or tent in deja_trouver:
            if tent in deja_trouver:
                console.print("[red]Tu as déjà essayer ça\n[/]")
            else:
                console.print('[red]Entrer un mot a 7 lettre\n[/]')
            tent = Prompt.ask(tentative_en_cours).upper()
        deja_trouver.append(tent)
        tenter, pattern = check_tent(tent, mot_choisie)
        mot_tenter_tout.append(tenter)
        Tusmo_patern_complet.append(pattern)

        console.print(*mot_tenter_tout, sep="\n")
        if tent == mot_choisie or len(deja_trouver) == tentative:
            fin_de_partie = True
    if len(deja_trouver) == tentative and tent != mot_choisie:
        console.print(f"\n[red]TUSMO X/{tentative}[/]")
        console.print(f'\n[green]Mot correct: {mot_choisie}[/]')
    else:
        console.print(f"\n[green]Tusmo {len(deja_trouver)}/{tentative}[/]\n")
    console.print(*Tusmo_patern_complet, sep="\n")


if __name__ == '__main__':
    console = Console()
    mot_choisie = choice(word_list)
    console.print(start_message)
    console.print(instruction)
    game(console, mot_choisie)