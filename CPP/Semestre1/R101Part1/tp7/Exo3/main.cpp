/*
 Programme : Compter les valeurs négatives d'un tableau
 But :  Compter les valeurs négatives d'un tableau
 Date de dernière modification : 19 octobre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES

    // Nombre de cases du tableau des températures
    const unsigned short int NB_CASES = 12;
    /*Tableau capable de stocker NB_CASES valeurs*/
    float tabValeur[NB_CASES];
    // Compteur de valeur négative
    int compteurValNegative;

    // TRAITEMENTS
    for (size_t indiceCaseCourante = 0; indiceCaseCourante <= NB_CASES - 1; indiceCaseCourante++)
    {
        cout << "Saisissez une valeur: " << endl;
        cin >> tabValeur[indiceCaseCourante];
    }
    for (size_t i = 0; i < NB_CASES-1; i++)
    {
        if (tabValeur[i] < 0)
        {
            compteurValNegative += 1;
        }
    }
    cout << "Il y a " << compteurValNegative << " valeur negative dans le tableau" << endl;

    return 0;
}