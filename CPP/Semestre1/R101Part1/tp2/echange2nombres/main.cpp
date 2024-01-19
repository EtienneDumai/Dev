/*
 Programme : EchangeDe2Nombres
 But :  Echanger 2 nombres
 Date de dernière modification : 15 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;


int main(void)
{
    // VARIABLES
    double nb1; // Le nombre a échanger avec nb2
    double nb2; // Le nombre a échanger avec nb1
    double copieNb1; // Copie de la valeur de nb1
    
    // TRAITEMENTS
    // clavier >> Saisir les 2 nombres à échanger >> nb1, nb2
    // clavier >> Saisir le nombre 1 >> nb1
    cout << "Valeur de nb1 : ";
    cin >> nb1; 

    // clavier >> saisir le nombre 2 >> nb2
    cout << "Valeur de nb2 : ";
    cin >> nb2;

    // nb1, nb2 >> échanger les 2 nombres >> nb1, nb2
    copieNb1=nb1;
    nb1=nb2;
    nb2=copieNb1; 

    // nb1, nb2 >> afficher le résultat de l'échange >> écran
    cout << "Apres echnage nb1 = " << nb1<< endl;
    cout << "Apres echnage nb2 = " << nb2 << endl;

     

}

