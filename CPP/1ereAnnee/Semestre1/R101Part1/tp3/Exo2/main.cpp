/*
 Programme : Signe d'un nombre
 But :  Déterminer le signe d'un nombre
 Date de dernière modification : 19 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;


int main(void)
{
    // VARIABLES
    double nb; // Nombre auquel on doit donner le signe
    string signe; //Signe du nombre

     // TRAITEMENTS
    // clavier >> Saisir le nombre auquel on doit déterminer le signe >> nb
    // clavier >> Saisir le nombre  >> nb
    cout << "Valeur de nb1 : ";
    cin >> nb; 
    // Déterminer le signe

    if (nb > 0)
    {
        signe = "positif";
    }
    else 
    {
        if (nb < 0)
        {
            signe = "negatif";
        }
        else
        {
            signe = "nul";
        }
    }
    
    cout << "Le nombre est " << signe << endl;


}