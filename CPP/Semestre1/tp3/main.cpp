/*
Programme : Bataille Navale
But : jouer au jeu de la Batialle Navale
Date de derniere modification : 21/11/23
Remarques : code conforme aux specifications internes donnee en cours
*/
#include "game-tools.h"

#include <iostream>
using namespace std;

/**
 * @brief Liste des directions dans lesquelles vont se générer les bateaux
 */
enum Direction
{
    /** La direction horizontale gauche a pour code direction 0*/
    DIR_HORIZONTALE_GAUCHE = 0,
    /** La direction horizontale droite a pour code direction 1*/
    DIR_HORIZONTALE_DROITE = 1,
    /** La direction verticale haut a pour code direction 2*/
    DIR_VERTICALE_HAUT = 2,
    /** La direction verticale bas a pour code direction 3*/
    DIR_VERTICALE_BAS = 3,
    /** La direction diagonale nord-ouest a pour code direction 4*/
    DIR_DIAGONALE_NO = 4,
    /** La direction diagonale nord-est a pour code direction 5*/
    DIR_DIAGONALE_NE = 5,
    /** La direction diagonale sud-ouest a pour code direction 6*/
    DIR_DIAGONALE_SO = 6,
    /** La direction diagonale sud-est a pour code direction 7*/
    DIR_DIAGONALE_SE = 7,
};

/**
 * @brief Liste du nombre de fois un bateau est touché
 */
enum Touche
{
    /** Le nombre de fois zero fois a pour code touche 0*/
    ZERO_FOIS = 0,
    /** Le nombre de fois une fois a pour code touche 1*/
    UNE_FOIS = 1,
    /** Le nombre de fois deux fois a pour code touche 2*/
    DEUX_FOIS = 2,
    /** Le nombre de fois trois fois a pour code touche 3*/
    TROIS_FOIS = 3,
    /** Le nombre de fois coule a pour code touche 4*/
    COULE = 4,
};
/**
 * @brief Enregistrement de type Coordonnees avec les valeurs x et y qui sont des int
 */
struct Coordonnees
{
    int x = 0; // Abscisse de la coordonnée
    int y = 0; // Ordonnée de la coordonnée
};
/**
 * @brief Enregistrement de type Coordonnees avec les valeurs x et y qui sont des int
 */
const unsigned short int NB_CASES_BATEAU = 4;
struct Bateau
{
    Coordonnees pos[NB_CASES_BATEAU]; // un bateau du jeu aura NB_CASES_BATEAU coordonnees
};

const unsigned short int NB_CASES = 9;
const unsigned short int NB_BATEAUX = 2; // Nombre de bateau qui seront présent dans le jeu

Touche bateau1 = ZERO_FOIS;
Touche bateau2 = ZERO_FOIS;

string pseudoJ1 = "";
string pseudoJ2 = "";
string gagnantDeLaPartie = "";

char tableauDeJeu[NB_CASES][NB_CASES]; // Tableau dans lequel va se dérouler la partie
                                       // Taille du tableau a l'horizontale et à la verticale (plateau de jeu carré)

Bateau bateaux[NB_BATEAUX]; // tableau de Bateaux
string ecartDe2 = "  ";
bool abandonJ1;
bool abandonJ2;
string msgErreurCo = "Veuillez entre une lettre entre A et I (en majuscule) et un chifre entre 1 et 9";
bool continuer;

/////////////////////////////////////////
// DECLARATIONS FONCTIONS / PROCEDURES //
/////////////////////////////////////////

void genererTableau(char tableau[NB_CASES][NB_CASES]);
// BUT : générer un tableau de caractère de NB_CASES de large et de long

void afficherTableau(char tableau[NB_CASES][NB_CASES]);
// BUT : Afficher le tableau entré en paramètre

void genererPositionBateaux(Bateau Bateaux[NB_BATEAUX]);
// BUT : générer aléatoirement les coordonnées des bateaux dans le tableau bateaux de type bateau

void afficherBateau();
// BUT : afficher les coordonées des bateaux

bool verifierCroisementBateaux(Bateau Bateaux[NB_BATEAUX]);
bool verifCroisBateau(Bateau Bateaux[NB_BATEAUX]);
/*BUT : verifier dans le tableau Bateaux de longueur NB_BATEAU si entre les 2 bateaux
il n'y a pas de croisement (coordonnée exacte dans les 2 bateaux)*/

void choisirPseudoDesJoueurs(string &joueur1, string &joueur2);
/* BUT : assigner des pseudo au joueur avec les chaines de caractère
qui seront passées en paramètre*/

void tirBateau(Bateau Bateaux[NB_BATEAUX], char tableau[NB_CASES][NB_CASES], string joueur1, string joueur2, bool &abanJ1, bool &abanJ2);
/* BUT : réaliser des tirs entre joueur1 et joueur2 chacun leurs tours en visant les
bateaux qui ont leurs coordonées dans le tableau Bateaux de longeur NB_BATEAUX*/

void verifierEtatBateaux(Bateau Bateaux[NB_BATEAUX]);
/* BUT : verifier si un bateau du tableau BateauX de longeur NB_BATEAUX si il est
coulé ou seulement toucher une ou plusieurs fois*/
void initialiserLaPartie();
void initialisationDesBateaux();
void affichage();
void affichageEnTete();
void jouerLaPartie();
void finaliserLaPartie();


string definirGagnant(string joueur1, string joueur2, string &gagnantPartie);
/* BUT : définir le gagnant de la parti entre joueur1 et joueur2 et la chaine de
caractère gagnant prendra son pseudo comme valeur*/
void dernierTirApresGagnant(string joueur1, string joueur2, string gagnantPartie);

void afficherGagnant(string gagnantPartie, bool abanJ1, bool abanJ2);
/* BUT : afficher le pseudo du gagnant de la partie qui est contenu dans la variable
gagnantPartie*/

// Procédure pour générer un tableau de 9x9 de caractères
#define DEBUG_ON = true;
int main()
{
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    initialiserLaPartie();
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif

    jouerLaPartie();
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    finaliserLaPartie();
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif

    return 0;
}

void afficherBateau()
{
    // Parcours des 2 bateaux du tableau Bateaux
    for (int indiceBateau = 0; indiceBateau < NB_BATEAUX; indiceBateau++)
    {
        // Afficher l'en-tête de la ligne
        cout << "Bateau " << (indiceBateau + 1) << (indiceBateau == 0 ? " (O) " : " (X) ") << " = ";
        // Afficher les coordonnées de tous les points du bateau
        for (int coordBateau = 0; coordBateau < NB_CASES_BATEAU; coordBateau++)
        {
            cout << " (" << char(bateaux[indiceBateau].pos[coordBateau].y + 64) << "," << bateaux[indiceBateau].pos[coordBateau].x << ")";
        }
        cout << endl;
    }
}
bool verifCroisBateau(Bateau Bateaux[NB_BATEAUX])
{
    int Bateaux1 = 0;
    int Bateaux2 = 1;
    bool aucunCroisement = true;
    for (int indiceBateau1 = 0; indiceBateau1 < NB_CASES_BATEAU; indiceBateau1++)
    {
        for (int indiceBateau2 = 0; indiceBateau2 < NB_CASES_BATEAU; indiceBateau2++)
        {
            if (indiceBateau1 == 1)
            {
                if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
            }
            else if (indiceBateau1 == 2)
            {
                if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
            }
        }
    }
    return aucunCroisement;
}
bool verifierCroisementBateaux(Bateau Bateaux[NB_BATEAUX])
{

    int Bateaux1 = 0;
    int Bateaux2 = 1;
    bool aucunCroisement = true;

    for (int indiceBateau1 = 0; indiceBateau1 < NB_CASES_BATEAU; indiceBateau1++)
    {
        for (int indiceBateau2 = 0; indiceBateau2 < NB_CASES_BATEAU; indiceBateau2++)
        {
            if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
            {
                aucunCroisement = false;
            }
        }
    }
    return aucunCroisement;
}

void choisirPseudoDesJoueurs(string &joueur1, string &joueur2)
{
    cout << "Quel est le pseudo du joueur1 ?" << endl;
    cin >> joueur1;
    effacer();
    cout << "Quel est le pseudo du joueur 2 ?" << endl;
    cin >> joueur2;
    effacer();
}

void tirBateau(Bateau Bateaux[NB_BATEAUX], char tableau[NB_CASES][NB_CASES], string joueur1, string joueur2, bool &abanJ1, bool &abanJ2)
{
    bool coValide = false;
    bool coDansIntervale = true;
    string reponse;
    char tirJoueurx;
    char tirJoueury;
    bool dansLeTableau = false;
    affichage();
    cout << " Au tour de : " << joueur1 << " dans" << endl;
    while (coValide != true)
    {
        coDansIntervale = true;
        effacer();

#ifdef DEBUG_ON
        cout << endl;
        cout << "INIT : " << __LINE__ << endl;
        cout << endl;
#endif

        affichage();
        cout << "Au tour de " << joueur1 << endl;
        cout << "Quelles sont les coordonnees de votre tir (ou abandonner @@) ?" << endl;
        cin >> reponse;
        effacer();
        for (int i = 0; reponse[i] != '\0'; i++)
        {
            if (i == 0)
            {
                tirJoueury = reponse[i];
            }
            else if (i == 1)
            {
                tirJoueurx = reponse[i];
            }
            else if (i > 1)
            {
                coDansIntervale = false;
            }
        }
        if (tirJoueurx == '@' && tirJoueury == '@')
        {
            if (joueur1 == pseudoJ1)
            {
                coDansIntervale = true;
                coValide = true;
                gagnantDeLaPartie = joueur2;
                abanJ1 = true;
            }
            else if (joueur1 == pseudoJ2)
            {
                coDansIntervale = true;
                coValide = true;
                gagnantDeLaPartie = joueur1;
                abanJ2 = true;
            }
        }
        if ((int(tirJoueury) - 64 >= 0 && int(tirJoueury) - 64 <= 10) && ((int(tirJoueurx) - 48) >= 0 && (int(tirJoueurx) - 48) <= 10) && coDansIntervale == true)
        {
            coValide = true;
            break;
        }
        else if (coValide != true)
        {
            affichage();
            afficherTexteEnCouleur(msgErreurCo, rouge, true);
            pause(3);
            coValide = false;
            reponse = "";
        }
    }

    for (int indiceBateau = 0; indiceBateau < NB_BATEAUX; indiceBateau++)
    {
        for (int indiceCase = 0; indiceCase < NB_CASES_BATEAU; indiceCase++)
        {
            if (Bateaux[indiceBateau].pos[indiceCase].x == (int(tirJoueurx) - 48) && Bateaux[indiceBateau].pos[indiceCase].y == int(tirJoueury) - 64)
            {
                dansLeTableau = true;
                if (dansLeTableau == true && indiceBateau == 0)
                {
                    tableau[int(tirJoueurx) - 49][int(tirJoueury) - 65] = 'O';
                }
                else if (dansLeTableau == true && indiceBateau == 1)
                {
                    tableau[int(tirJoueurx) - 49][int(tirJoueury) - 65] = 'X';
                }

                if (indiceBateau == 0)
                {
                    switch (bateau1)
                    {
                    case ZERO_FOIS:
                        bateau1 = UNE_FOIS;
                        break;
                    case UNE_FOIS:
                        bateau1 = DEUX_FOIS;
                        break;
                    case DEUX_FOIS:
                        bateau1 = TROIS_FOIS;
                        break;
                    case TROIS_FOIS:
                        bateau1 = COULE;
                        break;
                    default:
                        break;
                    }
                }
                if (indiceBateau == 1)
                {
                    switch (bateau2)
                    {
                    case ZERO_FOIS:
                        bateau2 = UNE_FOIS;
                        break;
                    case UNE_FOIS:
                        bateau2 = DEUX_FOIS;
                        break;
                    case DEUX_FOIS:
                        bateau2 = TROIS_FOIS;
                        break;
                    case TROIS_FOIS:
                        bateau2 = COULE;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    if (dansLeTableau == false)
    {
        tableau[int(tirJoueurx) - 49][int(tirJoueury) - 65] = '.';
    }
}
void initialisationDesBateaux()
{
}
void initialiserLaPartie()
{

// Appel de la procédure pour générer le tableau
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    genererTableau(tableauDeJeu);
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    choisirPseudoDesJoueurs(pseudoJ1, pseudoJ2);
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    // Appel de la procédure pour afficher le tableau
    afficherTableau(tableauDeJeu);
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    while ((!verifierCroisementBateaux(bateaux))||(!verifCroisBateau(bateaux)))
    {
        genererPositionBateaux(bateaux);
#ifdef DEBUG_ON
        cout << "INIT PARES : " << __LINE__ << endl;
#endif
        
    }
    

    // appel de la procédure pour generer les positions des bateaux
    /*genererPositionBateaux(bateaux);
    #ifdef DEBUG_ON
    cout << "INIT PARES : " << __LINE__ << endl;
#endif
if verif = false


    verifierCroisementBateaux(bateaux);
    // verifCroisBateau(bateaux);*/
    afficherBateau();
}

void affichage()
{
    affichageEnTete();
    afficherTableau(tableauDeJeu);
    afficherBateau();
}

void affichageEnTete()
{
    string titre = "B A T A I L L E  N A V A L E";
    cout << titre << endl;
    cout << endl;
    cout << "Chaque joueur doit couler un bateau de 4 cases " << endl
         << "(Vertical ou Horizontal ou Diagonale)" << endl;
    cout << endl;
}

void jouerLaPartie()
{

    while (gagnantDeLaPartie == "")
    {
        tirBateau(bateaux, tableauDeJeu, pseudoJ1, pseudoJ2, abandonJ1, abandonJ2);
        if (gagnantDeLaPartie == "")
        {
            tirBateau(bateaux, tableauDeJeu, pseudoJ2, pseudoJ1, abandonJ1, abandonJ2);
        }
        if (gagnantDeLaPartie == "")
        {
            gagnantDeLaPartie = definirGagnant(pseudoJ1, pseudoJ2, gagnantDeLaPartie);
            dernierTirApresGagnant(pseudoJ1, pseudoJ2, gagnantDeLaPartie);
        }
    }
}

void finaliserLaPartie()
{
    afficherGagnant(gagnantDeLaPartie, abandonJ1, abandonJ2);
}

string definirGagnant(string joueur1, string joueur2, string &gagnantPartie)
{
    if (bateau1 == COULE)
    {
        gagnantPartie = joueur1;
    }
    else if (bateau2 == COULE)
    {
        gagnantPartie = joueur2;
    }
    else if (bateau1 == COULE && bateau2 == COULE)
    {
        gagnantPartie = joueur1 + " et " + joueur2;
    }
    return gagnantPartie;
}

void dernierTirApresGagnant(string joueur1, string joueur2, string gagnantPartie)
{
    if (gagnantPartie == pseudoJ1)
    {
        affichage();
        cout << pseudoJ2 << " tu a le droit de faire un dernier tir" << endl;
        pause(3);
        tirBateau(bateaux, tableauDeJeu, pseudoJ2, pseudoJ1, abandonJ1, abandonJ2);
        definirGagnant(joueur1, joueur2, gagnantDeLaPartie);
    }
    else if (gagnantPartie == pseudoJ2)
    {
        affichage();
        cout << pseudoJ1 << " tu a le droit de faire un dernier tir" << endl;
        pause(3);
        tirBateau(bateaux, tableauDeJeu, pseudoJ1, pseudoJ2, abandonJ1, abandonJ2);
        definirGagnant(joueur1, joueur2, gagnantDeLaPartie);
    }
}

void afficherGagnant(string gagnantPartie, bool abanJ1, bool abanJ2)
{
    if (gagnantPartie != pseudoJ1 && gagnantPartie != pseudoJ2)
    {
        cout << "Il ya a egalite bien jouer a tout les deux" << endl;
    }
    else if (abanJ1 == true)
    {
        cout << "Bien joue " << pseudoJ2 << ", " << pseudoJ1 << " a abandonne la partie" << endl;
    }
    else if (abanJ2 == true)
    {
        cout << "Bien joue " << pseudoJ1 << ", " << pseudoJ2 << " a abandonne la partie" << endl;
    }
    else
    {
        cout << "Bien jouer " << gagnantPartie << " tu as remporte cette partie";
    }
}

// Procédure pour générer un tableau de 9x9 vide
void genererTableau(char tableau[NB_CASES][NB_CASES])
{
    for (int indiceTableau1 = 0; indiceTableau1 < 9; indiceTableau1++)
    {
        for (int indiceTableau2 = 0; indiceTableau2 < 9; indiceTableau2++)
        {
            // Remplissage du tableau avec un caractère vide
            tableau[indiceTableau1][indiceTableau2] = ' ';
        }
    }
}
void genererPositionBateaux(Bateau Bateaux[NB_BATEAUX])
{
    for (unsigned short int indiceBateau = 0; indiceBateau < NB_BATEAUX; indiceBateau++)
    {
        bool diagOK = false;

        int nbDirBateau = random(0, 7);
        Bateaux[indiceBateau].pos[0].x = random(1, 9);
        Bateaux[indiceBateau].pos[0].y = random(1, 9);

        switch (nbDirBateau)
        {
        case DIR_HORIZONTALE_DROITE:
            if ((Bateaux[indiceBateau].pos[0].x + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y + i;
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x;
            }
            break;
        case DIR_HORIZONTALE_GAUCHE:
            if ((Bateaux[indiceBateau].pos[0].x + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y - 3) < 1)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y - i;
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x;
            }

            break;
        case DIR_VERTICALE_HAUT:
            if ((Bateaux[indiceBateau].pos[0].x + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x + i;
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y;
            }

            break;
        case DIR_VERTICALE_BAS:
            if ((Bateaux[indiceBateau].pos[0].x - 3) < 1)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y + 3) > 9)
            {
                genererPositionBateaux(bateaux);
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x - i;
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y;
            }
            break;
        case DIR_DIAGONALE_NO:
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) - 3) < 1)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true)
            {

                for (int i = 1; i <= 3; i++)
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x + i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y - i;
                }
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x <= 9 || Bateaux[indiceBateau].pos[3].y >= 1)
                {
                    diagOK = true;
                }
            }

            break;
        case DIR_DIAGONALE_NE:
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true)
            {

                for (int i = 1; i <= 3; i++)
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x + i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y + i;
                }
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x <= 9 && Bateaux[indiceBateau].pos[3].y <= 9)
                {
                    diagOK = true;
                }
            }

            break;
        case DIR_DIAGONALE_SE:
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) - 3) < 1)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) + 3) > 9)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true)
            {

                for (int i = 1; i <= 3; i++)
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x - i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y + i;
                }
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x >= 1 || Bateaux[indiceBateau].pos[3].y <= 9)
                {
                    diagOK = true;
                }
            }

            break;
        case DIR_DIAGONALE_SO:
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) - 3) < 1)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) - 3) < 1)
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true)
            {

                for (int i = 1; i <= 3; i++)
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x - i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y - i;
                }
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x >= 1 || Bateaux[indiceBateau].pos[3].y >= 1)
                {
                    diagOK = true;
                }
            }

            break;

        default:
            break;
        }
    }
}
// Procédure pour afficher le tableau
void afficherTableau(char tableau[NB_CASES][NB_CASES])
{
    // Affichage de la ligne supérieure avec des lettres de A à I
    cout << "  "; // Deux espaces initiaux pour l'alignement
    for (char lettre = 'A'; lettre < 'A' + NB_CASES; lettre++)
    {
        cout << lettre << " "; // Un espace après chaque lettre pour les séparer
    }
    cout << endl;

    for (int indiceTableau1 = 0; indiceTableau1 < NB_CASES; indiceTableau1++)
    {
        // Affichage des chiffres sur le côté gauche
        cout << indiceTableau1 + 1 << " "; // Espace après le chiffre pour l'alignement des cases

        for (int indiceTableau2 = 0; indiceTableau2 < NB_CASES; indiceTableau2++)
        {
            // Affichage du contenu de la case
            if (indiceTableau2 < NB_CASES - 1)
            {
                cout << tableau[indiceTableau1][indiceTableau2] << ' ';
            }
            else
            {
                cout << tableau[indiceTableau1][indiceTableau2]; // Un espace après chaque caractère pour les séparer
            }
        }

        // Affichage des chiffres sur le côté droit après un espace supplémentaire pour l'aligner après la lettre I
        cout << " " << indiceTableau1 + 1 << endl; // Un espace avant le chiffre de droite pour l'alignement
    }

    // Affichage de la ligne inférieure avec des lettres de A à I
    cout << "  "; // Deux espaces initiaux pour l'alignement
    for (char lettre = 'A'; lettre < 'A' + NB_CASES; lettre++)
    {
        cout << lettre << " "; // Un espace après chaque lettre pour les séparer
    }
    cout << endl;
}
