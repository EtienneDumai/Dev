/*
 Programme : Fonction Verification d'une note
 But : Faire une fonction qui Vérifie si un nombre est une note (nombre entre 0 et 20)
 Date de dernière modification : 07 novembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

bool estUneNote(float note);
// BUT : retourne vrai si la valeur de note est comprise entre 0 et 20 et faux sinon

int main(void)
{
    float nb;
    cout << "Quel nombre voulez vous choisir?" << endl;
    cin >> nb;
    cout << nb << (estUneNote(nb) ? " est" : " n'est pas")<<" une note" << endl;
}
bool estUneNote(float note)
{
    return (note >= 0 && note <= 20);
}