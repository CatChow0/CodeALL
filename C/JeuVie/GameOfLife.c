#include <stdio.h>
#include <stdlib.h>
#include <time.h>           //Librairi Integration Temps
#include <SDL2/SDL.h>       Librairi Interface Graphique
// #include <SDL2/SDL_ttf.h>   //Librairi Text

// --------------------------------------------------------- //
// Defini la taille de l'affichage et la taille des cellules //
// --------------------------------------------------------- //

#define RENDER_WIDTH 1920
#define RENDER_HEIGHT 1080
#define CELL_SIZE 3
// --------------------------------- //
// Defini la grille du jeu de la vie //
// --------------------------------- // 

int SCREEN_WIDTH;    // Taille de l'affichage
int SCREEN_HEIGHT;    // Taille de l'affichage

int grid[RENDER_HEIGHT/CELL_SIZE][RENDER_WIDTH/CELL_SIZE];
int new_grid[RENDER_HEIGHT/CELL_SIZE][RENDER_WIDTH/CELL_SIZE];

// ---------------- //
// Autres Variables //
// ---------------- //

int num = 1;        // Nombre comptant les générations déjà passé
int Choix = 0;      // Choix de l'utilisateur pour continuer ou arreter
int generation = 0; // Nombre de génération
int num_max = 2000; // Nombre génération par cycle
int gen_temp = 1;   // Nombre de génération avant de print la génération actuelle
long clk_tck = CLOCKS_PER_SEC;
clock_t t1, t2, t3;

// ----------------------------------------- //
// Place les cellules initiale sur la grille //
// ----------------------------------------- //

void init_grid() {
    srand(time(NULL));
    for(int i = 0; i < SCREEN_HEIGHT/CELL_SIZE; i++) {
        for(int j = 0; j < SCREEN_WIDTH/CELL_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// ------------------------------------- //
// Compte le nombre de cellules voisines //
// ------------------------------------- //

int count_neighbors(int x, int y) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) continue;
            int ni = (x + i + SCREEN_HEIGHT/CELL_SIZE) % (SCREEN_HEIGHT/CELL_SIZE);
            int nj = (y + j + SCREEN_WIDTH/CELL_SIZE) % (SCREEN_WIDTH/CELL_SIZE);
            if(grid[ni][nj]) count++;
        }
    }
    return count;
}

// -------------------------------------------------------------------- //
// Acualise la grille du jeu en fontion du nombre de voisin par cellule //
// -------------------------------------------------------------------- //

void update_grid() {
    for(int i = 0; i < SCREEN_HEIGHT/CELL_SIZE; i++) {
        for(int j = 0; j < SCREEN_WIDTH/CELL_SIZE; j++) {
            int count = count_neighbors(i, j);

            // --------------------------------------------------- //
            // Verifie qu'il n'y ait pas trop de cellules voisines //
            // --------------------------------------------------- //

            if(grid[i][j]) {
                if(count < 2 || count > 3) {
                    new_grid[i][j] = 0; // Si trop ou pas assez de cellules voisines, tue la cellule
                } else {
                    new_grid[i][j] = 1; // Sinon, la cellule vie
                }
            } else {
                if(count == 3) {
                    new_grid[i][j] = 1; // Si y'a assez de cellules voisines, la cellule vie
                } else {
                    new_grid[i][j] = 0; // Sinon, la cellule est tue
                }
            }
        }
    }

    // --------------------------------------------------------------- //
    // Actualise la grille par rapport au nombre de voisin par cellule //
    // --------------------------------------------------------------- //

    for(int i = 0; i < SCREEN_HEIGHT/CELL_SIZE; i++) {
        for(int j = 0; j < SCREEN_WIDTH/CELL_SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

// -------------------------- //
// Affiche la grille actuelle //
// -------------------------- //

void draw_grid(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);        // Couleur de l'arrière plan
    SDL_RenderClear(renderer);                           // Fait le rendu de l'arrière plan
    SDL_SetRenderDrawColor(renderer, 200, 200, 200,255);   // Couleur des cellules

    // ---------------------------------- //
    // Dessine les cellules sur la grille //
    // ---------------------------------- //

    for(int i = 0; i < SCREEN_HEIGHT/CELL_SIZE; i++) {
        for(int j = 0; j < SCREEN_WIDTH/CELL_SIZE; j++) {
            if(grid[i][j]) {
                SDL_Rect rect = { j*CELL_SIZE, i*CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

// --------------------------------------------------------------------- //
// Initialise Le jeu en appellant les fonctions d'affichage et de grille //
// --------------------------------------------------------------------- //

int main(int argc, char* argv[]) {

    // --------------------------------- //
    // Choix de la taille de l'affichage //
    // --------------------------------- //

    int screen_size;
    printf("Choisissez la taille de l'affichage: \n1: 480p\n2: 720p (default) \n3: 1080p\n");
    scanf("%d", &screen_size);

    if (screen_size == 1) {
        SCREEN_HEIGHT = 480; 
        SCREEN_WIDTH = 704;
    } else if (screen_size == 2) {
        SCREEN_HEIGHT = 720;
        SCREEN_WIDTH = 1280;
    } else if (screen_size == 3) {
        SCREEN_HEIGHT = 1080;
        SCREEN_WIDTH = 1920;
    } else if (screen_size > 3 || screen_size < 1) { // Taille par defaut 720p
        SCREEN_HEIGHT = 720;
        SCREEN_WIDTH = 1280;
        printf("\nErreur /!\\ la taille par defaut a été appliqué.");
    }

    // ---------------------- //
    // Crée la fenetre de jeu //
    // ---------------------- //

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Jeu de la Vie", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    init_grid(); // Crée la grille initiale

    // TTF_init();

    // TTF_Font* Arial = TTF_OpenFont("Arial.ttf", 26);
    // SDL_Color Red = {255, 0, 0};
    // SDL_Surface* textSurf = TTF_RenderTextSolid(Arial, "Test", Red);
    // SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurf);
    // SDL_Rect textRect = {30, 30, textSurf->w, textSurf->h};
    // SDL_FreeSurface(textSurf);
    // TTF_CloseFont(Arial);

    // ------------- //
    // Boucle du Jeu //
    // ------------- //
    t1 = clock();

    while(1) { 
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                SDL_Quit();
                return 0;
            }
        }
        // SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        update_grid();                  // Met a jour la grille
        draw_grid(renderer);            // Rendu de la grille
        SDL_RenderPresent(renderer);    // Rendu de l'affichage actuelle
        t2 = clock();
        t3 = clock();  
        SDL_Delay(1);                   // Temps entre chaque génération de cellules
        generation++;

        // printf("Generation %d\n", generation); // Affiche la génération actuelle de cellules

        // -------------------------------------------- //
        // Demande a l'utilisateur si il veux continuer //
        // -------------------------------------------- //

        if(num == num_max) {
            printf("\nNous somme a la generation %d\nTemps ecoule depuis le début : %lf (s)\nVoulez vous ARRETER ici ou CONTINUER la simulation :\n1. Arreter\n2. Continuer\n3. Poursuivre pour 10 000 generation\nVeuillez entrez le chiffre de l'option choisie: ", generation, (double)(t2-t1)/(double)clk_tck);
            scanf("%d", &Choix);

            if(Choix == 1) {    // Arrete le programme
                // TTF_Quit();
                return 0;
            } else if (Choix == 2) { 
                num = 1;
            } else if (Choix == 3) { 
                num_max = 10000;
                num = 1;
            } else if (Choix > 3) {
                num = 1;
                printf("\nL'option par defaut(2) a ete applique");
            }

        } else if (num < num_max) {
            num++;
            // printf("\nnum %d", num); Affiche la valeur actuelle du num
        } else if (num > num_max) {
            num = 1;
        } 
        if (gen_temp < 100) {
            gen_temp++;
            // printf("%d", gen_temp);
        } else if (gen_temp > 99) {
            printf("\nGeneration actuelle : %d", generation); // Affiche la génération actuelle toute les x génération
            gen_temp = 1;
        }

    } 
}