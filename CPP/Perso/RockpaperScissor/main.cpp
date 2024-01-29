/**
 * @file main.cpp
 * @author Dumai Etienne
 * @brief Jeu du Pierre Papier Ciseaux
 * @date 2024-01-26
 */

#include <iostream>
#include "game-tools.h"

enum Signe
{
    PAPIER = 0,
    PIERRE = 1,
    CISEAUX = 2
};
bool gagnantJ1 = false;
bool gagnantJ2 = false;
bool egalite = false;
string gagnantPartie;
string pseudoJ1;
string pseudoJ2;
int signeJ1;
int signeJ2;
void choisirPseudo(string &pseudo1, string &pseudo2);
void tirerUnSigne(int signe1, int signe2, bool &gagnant1, bool &gagnant2, bool &egaliteJeu);
void definirGagnant(bool gagnant1, bool gagnant2, string &gagnantFinal);
void afficherGagnant();
int main()
{
    choisirPseudo(pseudoJ1, pseudoJ2);
    tirerUnSigne(signeJ1, signeJ2, gagnantJ1, gagnantJ2, egalite);
    definirGagnant(gagnantJ1, gagnantJ2, gagnantPartie);
    afficherGagnant();
}

void choisirPseudo(string &pseudo1, string &pseudo2)
{
    bool pseudoDiff = false;
    while (!pseudoDiff)
    {
        effacer();
        cout << "Quel est le pseudo du joueur 1 ?" << endl;
        cin >> pseudo1;
        effacer();
        cout << "Quel est le pseudo du joueur 2 ?" << endl;
        cin >> pseudo2;
        if (pseudo1 != pseudo2)
        {
            pseudoDiff = true;
        }
        else
        {
            effacer();
            cout << "Veuillez entrer des pseudos différents";
            pause(3);
        }
    }
}

void tirerUnSigne(int signe1, int signe2, bool &gagnant1, bool &gagnant2, bool &egaliteJeu)
{

    while (egaliteJeu != false)
    {
        signe1 = random(0, 2);
        signe2 = random(0, 2);
        switch (signe1)
        {
        case PAPIER:
            if (signe2 == PAPIER)
            {
                egaliteJeu = true;
            }
            else if (signe2 == PIERRE)
            {
                gagnant1 = true;
            }
            else
            {
                gagnant2 = true;
            }
            break;
        case PIERRE:
            if (signe2 == PAPIER)
            {
                gagnant1 = true;
            }
            else if (signe2 == PIERRE)
            {
                egaliteJeu = true;
            }
            else
            {
                gagnant2 = true;
            }
            break;
        case CISEAUX:
            if (signe2 == PAPIER)
            {
                gagnant1 = true;
            }
            else if (signe2 == PIERRE)
            {
                gagnant2 = true;
            }
            else
            {
                egaliteJeu=true;
            }
            break;
        default:
            break;
        }
    }
}

void definirGagnant(bool gagnant1, bool gagnant2, string &gagnantFinal)
{
    if (gagnant1 == true)
    {
        gagnantFinal = pseudoJ1;
    }
    if (gagnant2 == true)
    {
        gagnantFinal = pseudoJ2;
    }
}

void afficherGagnant()
{
    cout << "Bien jouer " << gagnantPartie << " tu as remporte cette partie" << endl;
}
