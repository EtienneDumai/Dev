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
string pseudoJ1;
string pseudoJ2;
int signeJ1;
int signeJ2;
void choisirPseudo(string &pseudo1, string &pseudo2);
int main(void)
{
    choisirPseudo(pseudoJ1, pseudoJ2);
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
