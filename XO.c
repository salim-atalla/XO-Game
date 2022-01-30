#include <stdio.h>





// Variables globales.
char tableau [3][3] ={  {'0','1','2'},
                        {'3','4','5'},
                        {'6','7','8'}
};
int fin = 0 ;
int nbrMouv = 0 ;
char joueur = 'X';





// Procédure qui affiche le jeu courant.
void afficherTableau ()
{
    printf("\n");

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {

            printf(" %c ", tableau[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("---+---+---");
        }
        printf("\n");
    }
    printf ("__________________\n");
}





char jouer (int choix) 
{
    // Calculer i et j.
    int tmp = choix;
    int i = tmp / 3;
    int j = tmp % 3;

    // Contrôleur de saisie.
    while (tableau[i][j] == 'X' || tableau[i][j] == 'O') {
        
        printf ("La case est deja occupee, veuillez choisir une autre ..\n");
        scanf (" %d", &tmp);
        i = tmp / 3;
        j = tmp % 3;
    }

    // Appliquer le changement sur la plateau du jeu.
    tableau[i][j] = joueur;
    // Incrémenter le nombre des cases occuppées.
    nbrMouv++; 
    // Afficher le plateau à chaque coup.
    afficherTableau();

    // Gérer les coups entre les joueurs.
    if (joueur == 'X') { return 'O'; }
    else { return 'X'; }
}





// Vérifier si le jeu est fini et retourner le joueur gagnant.
char gameover()
{
    // Vérifier les lignes croisées.
    if (tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2]) {
        fin = 1;
        return tableau[0][0];
    }
    if (tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0]) {
        fin = 1;
        return tableau[0][2];
    }

    // Véifier les lignes et les colonnes.
    for (int i=0; i<3; i++) {
        // Vérifier les lignes.
        if (tableau[i][0] == tableau[i][1] && tableau[i][1] == tableau[i][2]) {
            fin = 1;
            return tableau[i][0];
        }
        // Vérifier les colonnes.
        if (tableau[0][i] == tableau[1][i] && tableau[1][i] == tableau[2][i]) {
            fin = 1;
            return tableau[0][i];
        }  
    }
    // Si tous les cases sont remplis.
    if (nbrMouv == 9) {
        fin = 1;
        return '-';
    }
    return ' ';
}





/******************************** Programme Principale ********************************/
int main()
{
    // Initialiser les variables nécessaires.
    char gagnant = ' ';
    int choix;
    // Afficher le plateau au début du jeu.
    afficherTableau();

    // Commencer le jeu.
    while (fin != 1) {

        printf("Joueur: %c, Choisi une cellule.. ", joueur);
        scanf(" %d", &choix);
        
        joueur = jouer(choix);
        gagnant = gameover();
    }

    // Chercher le gagnant après avoir finir le jeu.
    if (gagnant != '-') {
        printf ("%c Win!", gagnant);
    } else {
        printf ("Egale!");
    }
   


    return 0;
}