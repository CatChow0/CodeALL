/* déclaration des fichiers joints */
#include <iostream>       //Flux d'entrée sortie I/O
#include <time.h>           //Pour le randomize
#include <stdio.h>          //
#include <stdlib.h>         //
#include <conio.h>          //Pour la fonction | system() |
#include <mem.h>            //
#include <dos.h>            //
#include <ctype.h>          //
#include <windows.h>        //Pour la fonction | Sleep() |
/* déclaration des fonctions global */
void jeu();                      //Fonction Jouer
void pause();                    //Equivalent a system("pause")
void options();                  //Configurer les options
void about();                    //About
void menu();                     //Main Menu
void test();                     //Fonction de test
void aide();                     //Aide
//simplification des noms
using namespace std;
/* déclaration des variables global */
int speed;                      //Durée du delay (vitesse du jeu)
int mainchoice;                 //Choix du Main Menu
int taille_serpent;             //Taille du serpent durant le jeu
int taille_serpentbase;         //Taille du serpent à la base
int position_serpent[2][800];   //Position du serpent (X)(Y)
int position_bille[2][1];       //Position de la bille (X)(Y)
int position_bonus[2][1];       //Position du bonus (X)(Y)
int timebonus;                  //Durée de vie du bonus
int direction;                  //Direction du serpent
int last_direction;             //Derniere direction
int nb_boule_mangee;            //Pour score, Nombre de boules mangées
int nb_bonus_mangee;            //Pour score, Nombre de bonus mangé
int nb_refresh;                 //Pour score, Nombre de refresh effectuer...
int score;                      //Pour score, Nombre de points 
int position_murmouvant[2][20]; //Position du mor mouvant
int taille_murmouvant;          //Taille mur mouvant
int nb_briquemouvant;           //Nombres de briques mouvantes
int position_briquemouvant[2][20];//Position des briques mouvantes
bool debugtype;                 //Type de debug a effectuer
bool updatebille;               //Met a jour la position de la bille
bool affichagebonus;            //Affiche le bonus
bool initserpent;               //Donne un point de départ au serpent
bool gameover;                  //Arrete le jeu
bool gameexit;                  //Quitte le jeu
bool help;                      //Affiche l'aide
bool debugmode;                 //Debug Mode ON/OFF
bool traversermur;              //Permet de traverser les murs
bool murcentral;                //Place un mur fixe au millieu de la map
bool murmouvantbool;            //Place un mur mouvant sur la map
bool bonusbool;                 //Place un bonus aléatoirement
bool sensmurmouvant;            //Indique le sens du mur (0=Hor. / 1=Ver.)
bool initmurmouvant;            //Initialise le mur mouvant
bool briquemouvantbool;         //Place des briques mouvante sur la map
bool initbriquemouvant;         //Initialisation des briques mouvantes
char player[25];                //Nom du joueur
char lastkey;                   //Dernière entrée
char screen[42][22];            //Ecran du jeu...
//--------------------------------------------------------------
//----------------------------MAIN------------------------------
//--------------------------------------------------------------
int main()
  {
  /* Initialisation primaire */ 
  speed=6;
  debugmode=0;  
  murcentral=0;
  bonusbool=0;
  briquemouvantbool=0;
  murmouvantbool=0;
  traversermur=0;
  taille_serpentbase=5;
  taille_murmouvant=10;
  nb_briquemouvant=5;
  srand(time(NULL));
  /* Welcome Message */  
  cout<<"-------------------------------------------------------\n";
  cout<<"----------Bienvenue dans le jeu du Serpent-------------\n";
  cout<<"-------------------------------------------------------\n";
  cout<<"\n";
  cout<<"		      .-----.  \n";
  cout<<"~~~~~~~~~~~~~~~~~~~~~~       O\\  \n";
  cout<<"(   (    (    (   (            ---.    \n";
  cout<<"~~~~~~~~~~~~~~~~~~~~\\             /===<\n";
  cout<<"		     -------------   \n\n\n";
  cout<<"-------------------------------------------------------\n";  
  cout<<"--------Programme realise par Patrick Vultier----------\n";
  cout<<"-------------------------------------------------------\n\n\n";  
  do
    {
    /* Initialisation récursive */
    lastkey=4;
    taille_serpent=taille_serpentbase;
    gameover=0;
    gameexit=0;
    updatebille=1;
    initserpent=1;
    score=0;
    nb_boule_mangee=0;
    nb_bonus_mangee=0;
    nb_refresh=0;
    affichagebonus=0;
    initmurmouvant=1;
    initbriquemouvant=1;
    /* Routine primaire */
    menu();  
    }while(mainchoice!=5);
}
//--------------------------------------------------------------
//----------------------------MENU------------------------------
//--------------------------------------------------------------
void menu()
  {
  cout<<"-------------------------------------------------------\n";
  cout<<"-------------------MAIN MENU---------------------------\n";
  cout<<"-------------------------------------------------------\n";
  cout<<"                   1 - Jouer\n";
  cout<<"                   2 - Options\n";
  cout<<"                   3 - Aide\n";
  cout<<"                   4 - A propos de Serpent\n";
  cout<<"                   5 - QUITTER\n";
  cout<<"-------------------------------------------------------\n";
  cout<<"Votre choix: ";
  cin>>mainchoice;
  cout<<endl;
  switch(mainchoice)
    {
    case 1 : jeu();
             break;  
    case 2 : options();
             break;
    case 3 : aide();
             break;
    case 4 : about();
             break;
    case 5 : break;
    default: cout<<"         \n!!! Veuillez entrer un choix !!!\n";
             break;
    }
}
//--------------------------------------------------------------
//--------------------------OPTIONS-----------------------------
//--------------------------------------------------------------
void options()
  {
  /* Déclaration variables locals */
  int temp;
  int choice;
  bool reask=0;
  /* Boucle principal */      
  do
    {
    system("cls");  
    cout<<"-------------------------------------------------------\n";
    cout<<"----------------------OPTIONS--------------------------\n";
    cout<<"-------------------------------------------------------\n";
    cout<<"Options actuelle:\n";
    cout<<"  1 - Vitesse: "<<speed<<endl;
    cout<<"  2 - Nom du Joueur: "<<player<<endl;
    cout<<"  3 - Taille du serpent: "<<taille_serpentbase<<" segements\n";
    cout<<"  4 - Debug Mode: ";
    if(debugmode==1)
      cout<<"ON\n";
    else
      cout<<"OFF\n";
    cout<<"  5 - Options de la map\n";
    cout<<"  6 - RETOUR - Main Menu\n";
    cout<<"-------------------------------------------------------\n";
    cout<<"\nQue voulez-vous changer: ";
    cin>>choice;
    cout<<endl;
    switch(choice)
      {
      case 1 : do
                 {
                 reask=0;
                 cout<<"Veuillez entrer une vitesse (ente 1 et 10): ";
                 cin>>temp;
                 cout<<endl;
                 if(temp<=10 && temp>=1)
                   speed=temp;
                 else
                   reask=1;
                 }while(reask==1);              
               break;
      case 2 : cout<<"Veuillez entrer votre nom: ";
               cin>>player;
               cout<<endl;
               break;
      case 3 : do
                 {
                 reask=0;
                 cout<<"Veuillez entrer une taille (entre 3 et 15): ";
                 cin>>temp;
                 cout<<endl;
                 if(temp<=15 && temp>=3)
                   taille_serpentbase=temp;
                 else
                   reask=1;
                 }
                 while(reask==1);              
               break;
      case 4 : if(debugmode==1)
                 debugmode=0;
               else
                  debugmode=1;
               cout<<"Debug mode is: ";
               if(debugmode==1)
                 {
                 cout<<"ON\n";
                 cout<<"Les ecrans de Debug apparaitrons lors du jeu !\n";
                 Sleep(2000);
                 }
               else
                 cout<<"OFF\n";
               Sleep(1000);
               break;
      case 5 : /* Boucle principal */      
               do
                 {
                 system("cls");  
                 cout<<"-------------------------------------------------------\n";
                 cout<<"--------------------MAP OPTIONS------------------------\n";
                 cout<<"-------------------------------------------------------\n";
                 cout<<"Options actuelle de la map:\n";
                 cout<<"  1 - Traverser les murs: ";
                 if(traversermur==1)
                   cout<<"ON\n";
                 else
                   cout<<"OFF\n";
                 cout<<"  2 - Mur central: ";
                 if(murcentral==1)
                   cout<<"ON\n";
                 else
                   cout<<"OFF\n";
                 cout<<"  3 - Mur mouvant: ";
                 if(murmouvantbool==1)
                   cout<<"ON\n";
                 else
                   cout<<"OFF\n";
                 cout<<"  4 - Taille mur mouvant: "<<taille_murmouvant<<endl;
                 cout<<"  5 - Bonus: ";
                 if(bonusbool==1)
                   cout<<"ON\n";
                 else
                   cout<<"OFF\n";
                 cout<<"  6 - Briques mouvantes: ";
                 if(briquemouvantbool==1)
                   cout<<"ON\n";
                 else
                   cout<<"OFF\n";
                 cout<<"  7 - Nombres briques mouvantes: "<<nb_briquemouvant<<endl;
                 cout<<"  8 - RETOUR - Options Menu\n";
                 cout<<"-------------------------------------------------------\n";
                 cout<<"\nQue voulez-vous changer: ";
                 cin>>choice;
                 cout<<endl;
                 switch(choice)
                   {
                   case 1 : if(traversermur==1)
                              traversermur=0;
                            else
                              traversermur=1;
                            break;
                   case 2 : if(murcentral==1)
                              murcentral=0;
                            else
                              murcentral=1;
                            break;
                   case 3 : if(murmouvantbool==1)
                              murmouvantbool=0;
                            else
                              murmouvantbool=1;
                            break;
                   case 4 : do
                              {
                              reask=0;
                              cout<<"Veuillez entrer une taille (ente 1 et 20): ";
                              cin>>temp;
                              cout<<endl;
                              if(temp<=20 && temp>=1)
                                taille_murmouvant=temp;
                              else
                                reask=1;
                              }
                            while(reask==1);              
                            break;
                   case 5 : if(bonusbool==1)
                              bonusbool=0;
                            else
                              bonusbool=1;
                            break;
                   case 6 : if(briquemouvantbool==1)
                              briquemouvantbool=0;
                            else
                              briquemouvantbool=1;
                            break;
                   case 7 : do
                              {
                              reask=0;
                              cout<<"Veuillez entrer un nombre (ente 1 et 20): ";
                              cin>>temp;
                              cout<<endl;
                              if(temp<=20 && temp>=1)
                                nb_briquemouvant=temp;
                              else
                                reask=1;
                              }
                            while(reask==1);              
                            break;
                   case 8 : break;
                   default: cout<<"         \n!!! Veuillez entrer un choix !!!\n";
                            break;
                   }           
                 }
               while(choice!=8);
               break;
      case 6 : break;
      default: cout<<"         \n!!! Veuillez entrer un choix !!!\n";
               break;
      }
    }while(choice!=6);
  system("cls");
}
//--------------------------------------------------------------
//----------------------------AIDE------------------------------
//--------------------------------------------------------------
void aide()
  {
  /* Affichage des consignes */ 
  system("cls");
  cout<<"-------------------------------------------------------\n";
  cout<<"-------------------------Aide--------------------------\n";
  cout<<"-------------------------------------------------------\n";
  cout<<"---------Clavier                                     \n\n";
  cout<<"     Touche Num. Pad \"2\"   =        Serpent bas        \n";
  cout<<"    ou Fleche \"Bas\"        =        Serpent bas        \n";
  cout<<"     Touche Num. Pad \"8\"   =        Serpent haut       \n";
  cout<<"    ou Fleche \"Haut\"       =        Serpent haut       \n";
  cout<<"     Touche Num. Pad \"4\"   =        Serpent gauche     \n";
  cout<<"    ou Fleche \"Gauche\"     =        Serpent gauche     \n";
  cout<<"     Touche Num. Pad \"6\"   =        Serpent droite     \n";
  cout<<"    ou Fleche \"Droite\"     =        Serpent droite     \n";  
  cout<<"     Touche \"B\"            =        Pause              \n";  
  cout<<"     Touche \"A\"            =        Aide               \n";
  cout<<"     Touche \"Q\"            =        Quitter            \n";
  Sleep(1000);
  cout<<endl;
  cout<<"---------Explication                                 \n\n";
  cout<<"   Vous devez simplement deplacer le serpent avec le   \n";
  cout<<"   clavier et attraper le bille sur l'ecran sans vous  \n";
  cout<<"   mordre la queue ou heurter un mur.                  \n";
  cout<<"   Bonne chance ;-)                                    \n";
  cout<<"-------------------------------------------------------\n";
  pause();
  system("cls");
}
//--------------------------------------------------------------
//---------------------------ABOUT------------------------------
//--------------------------------------------------------------
void about()
  {
  /* Affichage du a propos de */
  system("cls");
  cout<<"-------------------------------------------------------\n";
  cout<<"---------------A propos de Serpent---------------------\n";
  cout<<"-------------------------------------------------------\n";
  cout<<"  Cree par: CatChow\n";
  Sleep(1000);
  cout<<"  Version: 2.2\n";
  Sleep(1000);
  cout<<endl;
  cout<<"-------------------------------------------------------\n";
  Sleep(5000);
  system("cls");
  }
//--------------------------------------------------------------
//----------------------------JEU-------------------------------
//--------------------------------------------------------------
void jeu()
  {
  /* Fonction Local */
  void jeu_countdown();               //Fonction Compte-à-rebours
  void bille();                       //Fonction pour la bille
  void serpent();                     //Fonction pour le serpent
  void readkey();                     //Fonctione qui lit le clavier...
  void oldreadkey();                  //Lire le clavier pour Debug mode...
  void affichage();                   //affichage du tableau
  void check();                       //Entrée du player
  void resultat();                    //Affichage des resultats
  void over();                        //Affichage du GAME OVER
  void debug();                       //Fonction de debug
  void bonus();                       //Fonction pour le bonus
  void murmouvant();                  //Fonction pour le mur mouvant
  void briquemouvant();               //fonction pour briques mouvantes                                    
  /* Routine du jeu */
  system("cls");
  system("color 17");
  if(debugmode==1)                    //Check si mode de debug
    {
    system("color 1E");
    cout<<endl<<endl<<endl;
    cout<<"-------------------------------------------------------\n";    
    cout<<"----!!! ATENTION VOUS ETES EN MODE DE DEBUGAGE !!!-----\n";
    cout<<"-------------------------------------------------------\n";
    Sleep(3000);
    system("cls");
    system("color 17");
    }
  jeu_countdown();                    //Compte-à-rebours
  while(gameover==0 && gameexit==0) //Boucle d'affiche et saisie
    {
    if(help==1)                       //Vérification si demande d'aide
      aide();                           //Affichage si nécaissaire
    if(debugmode==1)                  //Vérification si demande Debug
      {
      debugtype=0;                      //Signifie que c'est avant les modifs
      debug();                          //Lancement de debug si nécaissaire
      }
    bille();                          //Positionnement de la bille
    if(bonusbool==1)
      bonus();                          //Positionnement du bonus
    if(murmouvantbool==1)
      murmouvant();                     //Positionnement des murs mouvants
    if(briquemouvantbool==1)
      briquemouvant();                  //Positionnement des briques mouvantes
    serpent();                        //Positionnement du serpent
    if(debugmode==1)                  //Vérification si demande Debug
      {
      debugtype=1;                      //Signifie que c'est après les modifs
      debug();                          //Lancement de debug si nécaissaire
      }
    affichage();                      //Affichage de screen
    if(debugmode==1)                //Vérification si demande Debug
      oldreadkey();                   //Lecture et delay pour debug mode
    else
      readkey();                        //Lit les touches et delay
    check();                          //Modification suite au touches enfoncée
                            //Calcul le score actuelle
    score=((nb_boule_mangee*speed)+(nb_bonus_mangee*50));  
    }
  Sleep(1500);
  if(debugmode==1)                    //Vérification si demande Debug
    {
    debugtype=2;                        //Signifie que c'est le jeu à quitter
    debug();                            //Lancement de debug si nécaissaire
    }
  over();                             //Affichage du GAME OVER
  resultat();                         //Affichage du score du player   
  system("color 07");
  system("cls");
}
//--------------------------------------------------------------
//--------------------------FAUSE-------------------------------
//--------------------------------------------------------------
void pause()
  {
  /* Fonction similaire au | system("pause") | */
  /* Mais evite l'emplois du Shell DOS */
  cout<<"Presser une touche pour continuer.\n";
  getch();
}
//--------------------------------------------------------------
//---------------------FONCTION POUR JEU------------------------
//--------------------------------------------------------------
  //--Jeu countdown---------------------------------------------
  void jeu_countdown()
    {
    /* Compte-a-rebours */
    system("cls");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"                               ------  \n";
    cout<<"                                     | \n";
    cout<<"                                     | \n";
    cout<<"                               ------  \n";
    cout<<"                                     | \n";
    cout<<"                                     | \n";
    cout<<"                               ------  \n";
    Sleep(1000);
    system("cls");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"                               ------  \n";
    cout<<"                                     | \n";
    cout<<"                                     | \n";
    cout<<"                               ------  \n";  
    cout<<"                              |        \n";
    cout<<"                              |        \n";
    cout<<"                               ------  \n";
    Sleep(1000);
    system("cls");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"                                    /| \n";
    cout<<"                                   / | \n";
    cout<<"                                  /  | \n";
    cout<<"                                     | \n";
    cout<<"                                     | \n";
    cout<<"                                     | \n";
    cout<<"                                     | \n";
    Sleep(1000);
    system("cls");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"                            ------     ------  \n";
    cout<<"                           |          |      | \n";
    cout<<"                           |          |      | \n";
    cout<<"                           |   ---    |      | \n";
    cout<<"                           |      |   |      | \n";
    cout<<"                           |      |   |      | \n";
    cout<<"                            -----      ------  \n";
    Sleep(1000);
    system("cls");
}
 
  //--Bonus-----------------------------------------------------  
  void bonus()
    {
    /* Déclaration des fonctions local */
    void affichage();
    /* Déclarations des variables locals */
    int aleat=0;
    /* Clignotement si bonus mangé */
    if((timebonus>0) && (affichagebonus==0))
      {
      system("cls");
      system("color C1");
      affichage();
      Sleep(50);
      system("cls");
      system("color 1C");
      affichage();
      system("color 17");
      timebonus=0;
      }
    /* Si bonus en cours d'affichage */
    if(affichagebonus==1)
      {
      if(timebonus==0)
        affichagebonus=0;
      else
        {
        /* Gestion du temps d'affichage du bonus */
        timebonus--;
        }
      }
    /* Si n'est pas en cours d'affichage */
    else
      {
      /* Random pour mettre le bonus ou pas */
      aleat=rand()%50;
      /* Positionnement du bonus si nécaissaire */
      if(aleat==25)
        {
        affichagebonus=1;
        timebonus=30;
        do
          {      
          /* Position sur axe X */
          position_bonus[0][0]=rand()%39;       //Donne une valeur sur axe X
          /* Position sur axe Y */
          position_bonus[1][0]=rand()%19;       //Donne une valeur sur axe Y
          }
        while(screen[(position_bonus[0][0]+1)][(position_bonus[1][0]+1)]!=' ');
        }
      }
    }
  //--Bille-----------------------------------------------------  
  void bille()
    {
    /* Déclaration de fonction local */
    void affichage();
    /* Au début du jeu */
    if(updatebille==1)
      {
      /* Cligontement */
      system("cls");
      system("color 71");
      affichage();
      Sleep(50);
      system("cls");
      system("color 17");
      affichage();
      do
        {      
        /* Position sur axe X */
        position_bille[0][0]=rand()%39;       //Donne une valeur sur axe X
        /* Position sur axe Y */
        position_bille[1][0]=rand()%19;       //Donne une valeur sur axe Y
        }
      while(screen[(position_bille[0][0]+1)][(position_bille[1][0]+1)]!=' ');
      updatebille=0;
      }  
    }
  //--OldReadKey---------------------------------------------------
  /* Pour debug mode */
  void oldreadkey()  
    {
    /* Lecture permanente des touches */
    lastkey=getch();
    Sleep(100);
    }
  //--ReadKey---------------------------------------------------
  void readkey()  
    {
    /* Déclaration des variables local */
    int count;
    /* Initialisation des variables */
    count=0;
    /* Boucle de saisie et de delay */
    while(count<=(110-(speed*10)))
      {
      Sleep(1);                      //Delay de une MircoSeconde
      count++;
      if(kbhit()==1)                 // Si clavier a été enfoncer
        lastkey=toupper(getch());    // Alors enregistrer la saisie
      }
    }
  //--Mur mouvant-----------------------------------------------
  void murmouvant()
    {
    /* Déclarations des variables locales */
    int aleatx;           //Valeur aléatoire pour axe X
    int aleaty;           //Valeur aléatoire pour axe Y
    int aleatsens;        //Valeur pour sens du mur (bool)
    int aleatupdate;      //Valeur pour modifier la position du mur
    int i;                //Pour boucle
    bool impossible;      //Valeur si position déjà prise
    /* Randomization pour update */
    aleatupdate=rand()%50;
    /* positionnement du mur mouvant */
    if(aleatupdate==25  || initmurmouvant==1)
      {
      do
        {
        initmurmouvant=0;
        /* Randomization */       
        aleatsens=rand()%2;
        impossible=0;
        //Donne une position au mur mouvant
        switch(aleatsens)
          {
          /* horizontal */
          case 0:  aleatx=rand()%(40-taille_murmouvant);
                   aleaty=rand()%19;
                   for(i=0 ;i<taille_murmouvant ; i++)
                     {
                     /* Axe X */
                     position_murmouvant[0][i]=(aleatx+i+1);
                     /* Axe Y */
                     position_murmouvant[1][i]=(aleaty+1);
                     }
                   break;
          /* vertical */
          case 1:  aleatx=rand()%39;
                   aleaty=rand()%(20-taille_murmouvant);
                   for(i=0 ;i<taille_murmouvant ; i++)
                     {
                     /* Axe X */
                     position_murmouvant[0][i]=(aleatx+1);
                     /* Axe Y */
                     position_murmouvant[1][i]=(aleaty+i+1);
                     }
                   break;
          }
        /* Check si position déjà utillisée */
        for(i=0 ; i<=taille_murmouvant ; i++)
          {
          if(screen[position_murmouvant[0][i]][position_murmouvant[1][i]]!=' ')
            impossible=1;
          }
        }
      while(impossible==0);
      sensmurmouvant=aleatsens;
      }
    }
  //--Brique mouvant-----------------------------------------------
  void briquemouvant()
    {
    /* Déclarations des variables locales */
    int aleatx;           //Valeur aléatoire pour axe X
    int aleaty;           //Valeur aléatoire pour axe Y
    int aleatupdate;      //Valeur pour modifier la position du mur
    int i;                //Pour boucle
    bool impossible;      //Valeur si position déjà prise
    /* Randomization pour update */
    aleatupdate=rand()%50;
    /* positionnement des briques mouvantes */
    if(aleatupdate==25  || initbriquemouvant==1)
      {
      do
        {
        initbriquemouvant=0;
        impossible=0;
        //Donne une position aux briques mouvantes
        for(i=0 ;i<nb_briquemouvant ; i++)
          {
          /* Axe X */
          aleatx=rand()%40;
          position_briquemouvant[0][i]=(aleatx+1);
          /* Axe Y */
          aleaty=rand()%20;
          position_briquemouvant[1][i]=(aleaty+1);
          }    
        /* Check si position déjà utillisée */
        for(i=0 ; i<=nb_briquemouvant ; i++)
          {
          if(screen[position_briquemouvant[0][i]][position_briquemouvant[1][i]]!=' ')
            impossible=1;
          }
        }
      while(impossible==0);
      }
    }
  //--Serpent---------------------------------------------------
  void serpent()
    {
    /* Déclaration variables local */
    int i, y;
    /* Initialisation du serpent (au debut de jeu) */
    if(initserpent==1)
      {
      last_direction=4;
      direction=4;
      /* position tête serpent sur axe X */
      position_serpent[0][0]=20;
      /* position tête serpent sur axe Y */
      position_serpent[1][0]=10;
      for(i=1 ; i<=taille_serpent ; i++)
        {
        /* position corps serpent sur axe X */
        position_serpent[0][i]=(20+i);
        /* position corps serpent sur axe Y */
        position_serpent[1][i]=(10);
        }
      initserpent=0;
      }
    /* Si c'est la première execution il va direct au else */    
    if(initserpent==0)
      {  
      /* Fait avancer le serpent en fonction de l'input */
      switch(direction)
        {
        /* Bottom - Bas */
                 /* Check si le serpent va faire demi-tour sur lui-meme */
        case 2 : if(last_direction!=8)
                   {
                   /* Décalage du corps du serpent */
                   for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=position_serpent[0][1];
                     /* Axe Y */
                   position_serpent[1][0]=((position_serpent[1][1])+1);
                   }
                 /* Si oui, il continue dans ca direction précédente */
                 else
                   {
                   /* Décalage du corps du serpent */
                   for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=position_serpent[0][1];
                     /* Axe Y */
                   position_serpent[1][0]=((position_serpent[1][1])-1); 
                   direction=8;
                   }
                 break;
        /* Left - Gauche */   
                /* Check si le serpent va faire demi-tour sur lui-meme */      
        case 4 : if(last_direction!=6)
                   {
                   /* Décalage du corps du serpent */
                   for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=((position_serpent[0][1])-1);
                     /* Axe Y */
                   position_serpent[1][0]=position_serpent[1][1];
                   }
                 /* Si oui, il continue dans ca direction précédente */
                 else
                   {
                   /* Décalage du corps du serpent */
                   for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=((position_serpent[0][1])+1);
                     /* Axe Y */
                   position_serpent[1][0]=position_serpent[1][1]; 
                   direction=6;
                   }
                 break;
        /* Right - Droite */  
                 /* Check si le serpent va faire demi-tour sur lui-meme */      
        case 6 : if(last_direction!=4)
                   {
                   /* Décalage du corps du serpent */
                   for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=((position_serpent[0][1])+1);
                     /* Axe Y */
                   position_serpent[1][0]=position_serpent[1][1];
                   }
                 /* Si oui, il continue dans ca direction précédente */
                 else
                   {
                   /* Décalage du corps du serpent */
                   for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=((position_serpent[0][1])-1);
                     /* Axe Y */
                   position_serpent[1][0]=position_serpent[1][1]; 
                   direction=4;
                   }
                 break;    
        /* Top - Haut */  
                 /* Check si le serpent va faire demi-tour sur lui-meme */           
        case 8 : if(last_direction!=2)
                   {
                   /* Décalage du corps du serpent */
                   for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=position_serpent[0][1];
                     /* Axe Y */
                   position_serpent[1][0]=((position_serpent[1][1])-1);
                   }
                 /* Si oui, il continue dans ca direction précédente */
                 else
                   {
                   /* Décalage du corps du serpent */
                  for(i=taille_serpent ; i>=0 ; i--)
                     {
                     /* Pour axe X */
                     position_serpent[0][i]=position_serpent[0][i-1];
                     /* Pour axe Y */
                     position_serpent[1][i]=position_serpent[1][i-1];
                     }
                   /* Création de la nouvelle tête du serpent */
                     /* Axe X */
                   position_serpent[0][0]=position_serpent[0][1];
                     /* Axe Y */
                   position_serpent[1][0]=((position_serpent[1][1])+1);
                   direction=2; 
                   }
                  break;
        /* Si auncune touche enfoncée, continuer sur ancienne direction */
        default: switch(last_direction)
                    {
                   /* Bottom - Bas */
                   case 2 : /* Décalage du corps du serpent */ 
                            for(i=taille_serpent ; i>=0 ; i--)
                              {
                              /* Pour axe X */
                              position_serpent[0][i]=position_serpent[0][i-1];
                              /* Pour axe Y */
                              position_serpent[1][i]=position_serpent[1][i-1];
                              }
                            /* Création de la nouvelle tête du serpent */
                              /* Axe X */
                            position_serpent[0][0]=position_serpent[0][1];
                              /* Axe Y */
                            position_serpent[1][0]=((position_serpent[1][1])+1);
                            direction=last_direction;
                            break;
                   /* Left - Gauche */      
                   case 4 :
                            for(i=taille_serpent ; i>=0 ; i--)
                              {
                              /* Pour axe X */
                              position_serpent[0][i]=position_serpent[0][i-1];
                              /* Pour axe Y */
                              position_serpent[1][i]=position_serpent[1][i-1];
                              }
                            /* Création de la nouvelle tête du serpent */
                              /* Axe X */
                            position_serpent[0][0]=((position_serpent[0][1])-1);
                              /* Axe Y */
                            position_serpent[1][0]=position_serpent[1][1];
                            direction=last_direction;
                            break;                 
                   /* Right - Droite */ 
                   case 6 :
                            for(i=taille_serpent ; i>=0 ; i--)
                              {
                              /* Pour axe X */
                              position_serpent[0][i]=position_serpent[0][i-1];
                              /* Pour axe Y */
                              position_serpent[1][i]=position_serpent[1][i-1];
                              }
                            /* Création de la nouvelle tête du serpent */
                              /* Axe X */
                            position_serpent[0][0]=position_serpent[0][1];
                              /* Axe Y */
                            position_serpent[1][0]=((position_serpent[1][1])+1);
                            direction=last_direction;
                            break;
                   /* Top - Haut */             
                   case 8 :
                            for(i=taille_serpent ; i>=0 ; i--)
                              {
                              /* Pour axe X */
                              position_serpent[0][i]=position_serpent[0][i-1];
                              /* Pour axe Y */
                              position_serpent[1][i]=position_serpent[1][i-1];
                              }
                            /* Création de la nouvelle tête du serpent */
                              /* Axe X */
                            position_serpent[0][0]=position_serpent[0][1];
                              /* Axe Y */
                            position_serpent[1][0]=((position_serpent[1][1])-1);
                            direction=last_direction;
                            break;
                   }
          }
        }
    else
      initserpent=0;
    /* Met a jour l'ancienne position */
    last_direction=direction;
    /* Vérification si le serpent peux traverser les murs */
    if(traversermur==1)
      {
      /* Vérification si la tête du serpent change de coté */
      if((position_serpent[0][0]>39 || position_serpent[0][0]<0) || (position_serpent[1][0]>19 || position_serpent[1][0]<0))
        {
        /* l'opposé pour Axe X >39 */
        if(position_serpent[0][0]>=39)
          {
          /* Axe X */
          position_serpent[0][0]=0;
          /* Axe Y */
          position_serpent[1][0]=position_serpent[1][1];
          }
        /* l'opposé pour Axe X <0 */  
        if(position_serpent[0][0]<0)
          {
          /* Axe X */
          position_serpent[0][0]=39;
          /* Axe Y */
          position_serpent[1][0]=position_serpent[1][1];
          }
        /* l'opposé pour Axe Y >19 */
        if(position_serpent[1][0]>19)
          {
          /* Axe X */
          position_serpent[0][0]=position_serpent[0][1];
          /* Axe Y */
          position_serpent[1][0]=0;
          }
        /* l'opposé pour Axe Y <0 */
        if(position_serpent[1][0]<0)
          {
          /* Axe X */
          position_serpent[0][0]=position_serpent[0][1];
          /* Axe Y */
          position_serpent[1][0]=19;
          }
        }
      }
    }
  //--Check-----------------------------------------------------    
  void check()
    {
    // Met a jour les actions effetuer en fonction des touches enfoncées
    /* Déclaration des varaibles */
    int i, y;
    /* Check demande pour quitter */
    if(lastkey=='q' || lastkey=='Q')
      gameexit=1;
    else
      gameexit=0;
    /* Check demande d'aide */
    if(lastkey=='a' || lastkey=='A')
      help=1;
    else
      help=0;
    /* Check demande de pause */
    if(lastkey=='b' || lastkey=='B')
      {
      cout<<endl<<endl;
      cout<<"VOUS ETES EN PAUSE !!!"<<endl<<endl;;
      pause();
      }
    /* Check Left - Gauche */
    if(lastkey=='4' || lastkey=='K')
      direction=4; 
    /* Check Right - Droite */
    if(lastkey=='6' || lastkey=='M')
      direction=6;
    /* Check Bottom - Bas */
    if(lastkey=='2' || lastkey=='P')
      direction=2;
    /* Check Top - Haut */
    if(lastkey=='8' || lastkey=='H')
      direction=8;
    /* Check si le serpent a manger la bille */
    /* Position sur axe X */
    if(position_serpent[0][0]==position_bille[0][0])
      {
      /* Position sur axe Y */
      if(position_serpent[1][0]==position_bille[1][0])
        {
        updatebille=1;            //Ce qui va mettre a jour la bille
        nb_boule_mangee++;        //Augmente le score 
        taille_serpent++;         //Augmente le taille su serpent
        }
      }
    /* Check si le serpent a manger le bonus */
    /* Position sur axe X */
    if(position_serpent[0][0]==position_bonus[0][0])
      {
      /* Position sur axe Y */
      if(position_serpent[1][0]==position_bonus[1][0])
        {
        nb_bonus_mangee++;
        affichagebonus=0;
        }
      }
    /* Check si le serpent touche le mur */
    if(traversermur==0)
      {
      for(i=0 ; i<taille_serpent ; i++)
        {
        /* position pour axe X */
        if(position_serpent[0][i]>=40 || position_serpent[0][i]<0)
          gameover=1;
        /* position pour axe Y */
        if(position_serpent[1][i]>=20 || position_serpent[1][i]<0)
          gameover=1;
        }
      }
    /* Check si serpent touche le mur central */
    if(murcentral==1)
      {
      for(i=0 ; i<taille_serpent ; i++)
        {
        if((position_serpent[1][i]==9) && ((position_serpent[0][i]>=10) && (position_serpent[0][i]<=30)))
          gameover=1;
        }
      }
    /* Check si serpent touche le mur mouvant */
    if(murmouvantbool==1)
      {
      for(i=0 ; i<taille_serpent ; i++)
        {
        for(y=0 ; y<taille_murmouvant ; y++)
          {
          if((position_serpent[0][i]==position_murmouvant[0][y]) && (position_serpent[1][i]==position_murmouvant[1][y]))
            gameover=1;
          }
        }
      }
    /* Check si serpent touche les briques mouvantes */
    if(briquemouvantbool==1)
      {
      for(i=0 ; i<taille_serpent ; i++)
        {
        for(y=0 ; y<nb_briquemouvant ; y++)
          {
          if((position_serpent[0][i]==position_briquemouvant[0][y]) && (position_serpent[1][i]==position_briquemouvant[1][y]))
            gameover=1;
          }
        }
      }
    /* Check si le serpent c'est mangé la queue */
    for(i=0 ; i<taille_serpent ; i++)
      {
      for(y=(i+1) ; y<taille_serpent ; y++)
        {
        /* Position sur axe X */
        if(position_serpent[0][i]==position_serpent[0][y])
          {
          /* Posistion sur axe Y */
          if(position_serpent[1][i]==position_serpent[1][y])
            gameover=1;
          }
        }
      }
    }
  //--Affichage-------------------------------------------------    
  void affichage()
    {
    /* Déclaration des variables local */
    int i, y;        //Pour compteur
    int ascii;       //Charactère spécial en ASCII
    char brique;     //Characatère spécial pour mur
    nb_refresh++;
    /* Remplissage de "screen" */
      /* Vidange de l'écran */
      for(i=0 ; i<42 ; i++)
        {
        for(y=0 ; y<22 ; y++)
          {
          screen[i][y]=' ';
          }
        }
      /* positionnement des murs */
        /* positionnement des murs haut et bas */
        ascii=205;
        brique=ascii;
        for(i=0 ; i<42 ; i++)
          {
          screen[i][0]=brique;            //Haut        ASCII: 205
          screen[i][21]=brique;           //Bas         ASCII: 205
          }
        /* Positionnement des murs gauche droite */
        ascii=186;
        brique=ascii;
        for(i=0 ; i<22 ; i++)
          {
          screen[0][i]=brique;               //Gauche       ASCII: 186
          screen[41][i]=brique;              //Droite       ASCII: 186
          }
        /*Positionnement des angles des murs*/
        ascii=201;
        brique=ascii;
        screen[0][0]=brique;                 //Haut-Gauche  ASCII: 201
        ascii=187;
        brique=ascii;
        screen[41][0]=brique;                //Haut-Droite  ASCII: 200
        ascii=200;
        brique=ascii;
        screen[0][21]=brique;                //Bas-Gauche   ASCII: 187
        ascii=188;
        brique=ascii;
        screen[41][21]=brique;               //Bas-Droite   ASCII: 188
      /* positionnement du mur central */
      if(murcentral==1)
        {
        ascii=205;
        brique=ascii;
         for(i=0 ; i<20 ; i++)
           screen[(i+1+10)][10]=brique;
        }
      /* positionnement du mur mouvant */
      if(murmouvantbool==1)
        {
        if(sensmurmouvant==0)
          ascii=205;
        if(sensmurmouvant==1)
          ascii=186;
        brique=ascii;
        for(i=0 ; i<taille_murmouvant ; i++)
          screen[(position_murmouvant[0][i]+1)][(position_murmouvant[1][i]+1)]=brique;
        }
      /* positionnement des briques mouvantes */
      if(briquemouvantbool==1)
        {
        ascii=178;     
        brique=ascii;
        for(i=0 ; i<nb_briquemouvant ; i++)
          screen[(position_briquemouvant[0][i]+1)][(position_briquemouvant[1][i]+1)]=brique;
        }
      /* positionnement de la bille */
      screen[(position_bille[0][0]+1)][(position_bille[1][0]+1)]='O';
      /* positionnement du bonus */
      if(affichagebonus==1)
        {
        screen[(position_bonus[0][0]+1)][(position_bonus[1][0]+1)]='#';
        }
      /* positionnement du serpent */
      for(i=0 ; i<taille_serpent ; i++)
        {
        screen[(position_serpent[0][i]+1)][(position_serpent[1][i]+1)]='+';
        }
    /* Affichage de "screen" */
    system("cls");
    for(i=0 ; i<22 ; i++)
      {
      for(y=0 ; y<42 ; y++)
        cout<<screen[y][i];
      /* Affichage du score a gauche */
      if(i==10)
         cout<<"         ------ ";
      if(i==11)
         cout<<"  SCORE | "<<score<<"\t |";
      if(i==12)
         cout<<"         ------ ";
      if(affichagebonus==1)
        {
        if(i==14)
          cout<<"         ------ ";
        if(i==15)
          cout<<"  BONUS | "<<timebonus<<"\t |";
        if(i==16)
          cout<<"         ------ ";
        }
      cout<<endl;
      }
    }
  //--Resultat--------------------------------------------------    
  void resultat()
    {
    /*Routine d'affichage si le player perds */
    if(gameover==1)
      {
      system("cls");
      cout<<"-------------------------------------------------------\n";
      cout<<"---------------Resume de la partie---------------------\n";
      cout<<"-------------------------------------------------------\n";
      cout<<"Bravo "<<player<<" vous avez bien jouer !\n\n";
      cout<<"votre score:            "<<score<<endl;
      cout<<"Nombre de mouvement:    "<<nb_refresh<<endl;
      cout<<"Nombre de bille mangee: "<<nb_boule_mangee<<endl;
      cout<<"Nombre de bonus mange:  "<<nb_bonus_mangee<<endl;
      cout<<"\n\n\n\n";
      pause();
      }
    /*Routine d'affichage si le player quitte */
    if(gameexit==1)
      {
      system("cls");
      cout<<"-------------------------------------------------------\n";
      cout<<"---------------Resume de la partie---------------------\n";
      cout<<"-------------------------------------------------------\n";
      cout<<"Attention "<<player<<" Vous aller quitter la partie !!!\n\n";
      cout<<"Vous avez mange: "<<nb_boule_mangee<<" billes";
      cout<<"Vous avez mange: "<<nb_bonus_mangee<<" bonus";
      cout<<"\n\n\n\n";
      pause();
      }
    }
  //--Game Over-------------------------------------------------
  void over()
    {
    /* Déclaration des variables local */
    bool colorsw;                //Lors fu flash du game over
    int i;                       //Pour compteur
    /* Affichage de game over avec ralentissement */
    system("cls");
    system("color 1C");
    cout<<"\n\n\n";
    cout<<" ----------------------------------------------------- \n";
    Sleep(100);
    cout<<"|          ------   ------   -      -   ------        | \n";
    Sleep(100);
    cout<<"|         |        |      | | \\    / | |              |\n";
    Sleep(100);
    cout<<"|         |        |      | |  \\  /  | |              |\n";
    Sleep(100);
    cout<<"|         |   ---  |------| |   \\/   | |----          |\n";
    Sleep(100);
    cout<<"|         |      | |      | |        | |              | \n";
    Sleep(100);
    cout<<"|         |      | |      | |        | |              | \n";
    Sleep(100);
    cout<<"|          ------                       ------        | \n";
    Sleep(100);
    cout<<"|          ------  |      |  ------  ------           | \n";
    Sleep(100);
    cout<<"|         |      | |      | |       |      |          | \n";
    Sleep(100);
    cout<<"|         |      |  |    |  |       |      |          | \n";
    Sleep(100);
    cout<<"|         |      |  |    |  |----   |------           | \n";
    Sleep(100);
    cout<<"|         |      |   |  |   |       | \\               |\n";
    Sleep(100);
    cout<<"|         |      |   |  |   |       |   \\             |\n";
    Sleep(100);
    cout<<"|          ------     ||     ------ |     \\           |\n";
    Sleep(100);
    cout<<" ----------------------------------------------------- \n";
    Sleep(1000);
    /* Clignotement de game over */
    colorsw=0;
    for(i=0 ; i<10 ; i++)
      {
      system("cls");
      if(colorsw==0)
        {
        colorsw=1;
        system("color 1C");
        }
      else
        {
        colorsw=0;
        system("color C1");
        }
      cout<<"\n\n\n";
      cout<<" ----------------------------------------------------- \n";
      cout<<"|          ------   ------   -      -   ------        | \n";
      cout<<"|         |        |      | | \\    / | |              |\n";
      cout<<"|         |        |      | |  \\  /  | |              |\n";
      cout<<"|         |   ---  |------| |   \\/   | |----          |\n";
      cout<<"|         |      | |      | |        | |              | \n";
      cout<<"|         |      | |      | |        | |              | \n";
      cout<<"|          ------                       ------        | \n";
      cout<<"|          ------  |      |  ------  ------           | \n";
      cout<<"|         |      | |      | |       |      |          | \n";
      cout<<"|         |      |  |    |  |       |      |          | \n";
      cout<<"|         |      |  |    |  |----   |------           | \n";
      cout<<"|         |      |   |  |   |       | \\               |\n";
      cout<<"|         |      |   |  |   |       |   \\             |\n";
      cout<<"|          ------     ||     ------ |     \\           |\n";
      cout<<" ----------------------------------------------------- \n";
      if(colorsw==1)
        {
        Sleep(200);
        system("cls");
        }
      else
        {
        Sleep(100);
        system("cls");
        }
      } 
    system("color 17");
    } 
  //--Debug-----------------------------------------------------    
  void debug()
    {
    /* Déclaration des varaibles local */
    int i;            //Pour compteur
    /* Routine de debuggage */
    system("cls");
    system("color 1E");
    cout<<"-------------------------------------------------------\n";    
    cout<<"--------------INFORMATIONS DE DEBUGAGES----------------\n";
    cout<<"-------------------------------------------------------\n";
    cout<<"((((((( DEBUG TYPE: \n";
    switch(debugtype)
      {
      case 0: cout<<"((((((( Premiere etape de la routine\n";
              cout<<"((((((( Apres la fonction \"check\"...\n\n\n";
              break;
      case 1: cout<<"((((((( Seconde etape de la routine\n";
              cout<<"((((((( Apres les fonction \"bille\" et \"serpent\"\n\n";
              cout<<" LORSQUE VOUS RECOMMENCEREZ, LA DIRECTION DU SERPENT\n";
              cout<<" SERA VAIDEE !!!!\n\n\n";
              break;
      case 2: cout<<"((((((( Troisieme etape de la routine\n";
              cout<<"((((((( Apres avoir quitter le boucle du jeu\n\n\n";
              break;      
      }
    cout<<"---Informations sur la bille\n";
    cout<<"Position bille X: "<<position_bille[0][0]<<endl;
    cout<<"               Y: "<<position_bille[1][0]<<endl;
    cout<<"Nombre de bille mangee: "<<nb_boule_mangee<<endl<<endl;
    cout<<"---Informations sur le bonus\n";
    cout<<"Position bonus X: "<<position_bonus[0][0]<<endl;
    cout<<"               Y: "<<position_bonus[1][0]<<endl;
    cout<<"Nombre de bonus mangee: "<<nb_bonus_mangee<<endl<<endl;
    cout<<"---Informations sur le mur mouvant\n";
        cout<<"Position mur mouvant X: ";
    for(i=0 ; i<taille_murmouvant ; i++)
      cout<<position_murmouvant[0][i]<<" - ";
    cout<<endl;
    cout<<"                     Y: ";
    for(i=0 ; i<taille_murmouvant ; i++)
      cout<<position_murmouvant[1][i]<<" - ";
    cout<<endl;
    cout<<"Taille mur mouvant: "<<taille_murmouvant<<endl;
    cout<<"Sens du mur mouvant: "<<sensmurmouvant<<endl;
    cout<<"Initialisation du mur mouvant: "<<initmurmouvant<<endl<<endl;
    cout<<"---Informations sur les briques mouvantes\n";
        cout<<"Position briques mouvantes X: ";
    for(i=0 ; i<nb_briquemouvant ; i++)
      cout<<position_briquemouvant[0][i]<<" - ";
    cout<<endl;
    cout<<"                           X: ";
    for(i=0 ; i<nb_briquemouvant ; i++)
      cout<<position_briquemouvant[1][i]<<" - ";
    cout<<endl;
    cout<<"Nombre de briques mouvantes: "<<nb_briquemouvant<<endl;
    cout<<"Initialisation des briques mouvant: "<<initbriquemouvant<<endl<<endl;
    cout<<"---Informations sur le serpent\n";
    cout<<"Longueur Serpent: "<<taille_serpent<<endl;
        cout<<"Position serpent X: ";
    for(i=0 ; i<taille_serpent ; i++)
      cout<<position_serpent[0][i]<<" - ";
    cout<<endl;
    cout<<"                 Y: "; 
    for(i=0 ; i<taille_serpent ; i++)
      cout<<position_serpent[1][i]<<" - ";
    cout<<endl;
    cout<<"Direction: "<<direction<<endl;
    cout<<"Last Direction: "<<last_direction<<endl;
    cout<<endl<<endl;
    cout<<"---Informations sur les \"bool\"\n";
    cout<<"Valeur de \"gameexit\"       : "<<gameexit<<endl;
    cout<<"Valeur de \"gameover\"       : "<<gameover<<endl;
    cout<<"Valeur de \"help\"           : "<<help<<endl;
    cout<<"Valeur de \"updatebille\"    : "<<updatebille<<endl;
    cout<<"Valeur de \"initserpent\"    : "<<initserpent<<endl;
    cout<<"Valeur de \"affichagebonus\" : "<<affichagebonus<<endl;
    cout<<"Valeur de \"bonusbool\"      : "<<bonusbool<<endl;
    cout<<"Valeur de \"traversermur\"   : "<<traversermur<<endl;
    cout<<"Valeur de \"murcentral\"     : "<<murcentral<<endl;
    cout<<"Valeur de \"murmouvantbool\" : "<<murmouvantbool<<endl;
    cout<<"Valeur de \"briquemouvantbool: "<<briquemouvantbool<<endl<<endl;
    cout<<"---Informations sur diverses\n";
    cout<<"Dernière touche entree: "<<lastkey<<endl;
    cout<<"Nombres de refresh de l\'ecran: "<<nb_refresh<<endl;
    cout<<"Score actuelle: "<<score<<endl;
    cout<<"Timer bonus: "<<timebonus<<endl<<endl;
    cout<<endl<<endl;
    pause();
    cout<<endl<<"REPRISE DU JEU NOW...";
    Sleep(1000);
    system("cls");
    system("color 17");
}