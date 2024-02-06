/*
 Programme : Afficher les lignes
 But :  Afficher un nombre de ligne choisie par l'utilisateur
 Date de dernière modification : 26 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/


#include <iostream>
using namespace std;


int main(void)
{
     // VARIABLES
    double NbLigne; // variable représente le nombre de ligne
    int i; // indice de la boucle
    // Clavier >> demande du nombre de ligne a afficher >> NbLigne 
    cout << "Quel nombre de ligne voulez vous affichez ?" << endl;
    cin >> NbLigne;

    for (i = 0 ; i < NbLigne ; i++)
    {
        cout << "*****" << endl;
    }
   
    
    

}
