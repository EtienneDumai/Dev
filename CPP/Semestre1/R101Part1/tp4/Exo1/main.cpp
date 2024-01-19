/*
 Programme : Saisie puis verif d'une note sans messages d'erreurs
 But :  Saisir une note et verifier si elle est comprise entre 0 et 20 sans envoyer de messages d'erreurs
 Date de dernière modification : 26 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/


#include <iostream>
using namespace std;


int main(void)
{
    // VARIABLES
    double valeur = -4; // variable saisie par l'utilisateur qui représente la note

    // TRAITEMENTS
    while (valeur < 0 || valeur > 20)
    {
         // clavier >> saisir une valeur entre 0 et 20 >> valeur
        cout << "Saisir une note : " << endl;
        cin >> valeur;
    }
    cout << "Merci.";
    
   
}





