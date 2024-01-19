/*
 Programme : Affciher 5 nombres suivants
 But :  Afficher les 5 nombres suivant du nombre demandé
 Date de dernière modification : 27 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/


#include <iostream>
using namespace std;


int main(void)
{
    //VARIABLE
    int i; // itérateur pour la boucle
    int NbEntier; //Nombre a partir duquel on va afficher les 5 suivants 

    //TRAITEMENTS

    cout<< "Quel est le nombre a partir duquel vous voulez connaitre les 5 suivant ?" << endl;
    cin>> NbEntier;


    for ( i = NbEntier + 1; i <= NbEntier + 5 ; i++)
    {
        cout << i << " ";
    }
    
}