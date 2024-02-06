/*
 Programme : Afficher un tableau
 But :  Afficher un tableau en entier
 Date de dernière modification : 19 octobre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;


int main(void)
{
    //VARIABLES

    //Nombre de cases du tableau des températures
    const unsigned short int NB_CASES=12;
    /*Tableau capable de stocker NB_CASES valeurs*/
    float tabTemperature[NB_CASES];

    //TRAITEMENTS
    for (size_t indiceCaseCourante = 0; indiceCaseCourante <= NB_CASES-1; indiceCaseCourante++)
    {
        cout << "Saisissez une valeur: "<< endl;
        cin >> tabTemperature[indiceCaseCourante];
    }
    for (size_t i = 0; i < NB_CASES; i++)
    {
        cout<< tabTemperature[i]<<" ; ";
    }
    
    
    

    return 0;
}