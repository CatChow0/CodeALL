#import des modules de base
from distutils.cmd import Command
from tkinter import *
import random
from playsound import playsound
from math import *
#personalisation de la fenetre
fenetre = Tk()                  #crée la fenetre
fenetre.title("Wattchow")       #donne un nom a la fenetre
fenetre.config(bg = "#6E6E6E")  #change la couleur de fond de la fenetre
fenetre.geometry("1280x720")    #defini la taille initiale de la fenetre
fenetre.maxsize(1920,1080)      #limite taille max fenetre
fenetre.minsize(854,480)        #limite taille min fenetre
#contenu initiale de la fentre
bouton1 = Button (fenetre, text = "Start", width=10, height=2,) #création du 1er bouton
bouton1.pack()
#Déplacement du bouton a chaque clic
def Clic(event):
    x = random.randint(50,fenetre.winfo_width()-50)
    y = random.randint(50,fenetre.winfo_height()-50)
    bouton1.place(x=x, y=y)  
    playsound("roblox-death-sound_1.mp3")
bouton1.bind("<Button-1>",Clic)
bouton1.pack
fenetre.mainloop()              #affiche la fenetre