/*
 Programme : Saisie puis verif d'une note avec messages d'erreurs
 But :  Saisir une note et verifier si elle est comprise entre 0 et 20 en envoyant des messages d'erreurs
 Date de dernière modification : 26 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/


#include <iostream>
using namespace std;


int main(void)
{
    // VARIABLES
    double valeur; // variable saisie par l'utilisateur qui représente la note

    // TRAITEMENTS
    while (true)
    {
        
        // clavier >> saisir une valeur entre 0 et 20 >> valeur
        cout << "Saisir une note : " << endl;
        cin >> valeur; 
        if (valeur > 0 && valeur < 20) //test pour savoir si la note est comprise entre 0 et 20
        {
            break; // elle est comprise entre 0 et 20 alors je sors de la boucle 
        }
        else
        {
            cout << "Valeur saisie non comprise entre 0 et 20 veuillez recommencer" << endl; //elle n'est pas comprise entre 0 et 20 je demande a l'user de recommencez

        }
        
    }
    
    cout << "Merci.";
    




}