/*
 Programme : Moyenne de notes
 But :  Calculer la moyenne d'un nombre de notes non connu a l'avance
 Date de dernière modification : 04 octobre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/
#include<iostream>
using namespace std;

int main(void)
{
    //VARIABLES
    bool indEgal;
    double nombre1;
    double nombre2;
    double nombre3;
    double max1;

    //TRAITEMENTS

    cout << "Quel est votre premier nombre" << endl;
    cin >> nombre1;
    cout << "Quel est votre deuxieme nombre" << endl;
    cin >> nombre2;
    cout << "Quel est votre troisieme nombre" << endl;
    cin >> nombre3;

    switch (nombre1, nombre2, nombre3)
    {
    case nombre1 > nombre2 :
        max1 = nombre1
        break;
    case nombre1 < nombre2 :
        max1 = nombre2
        break;
    case nombre1 == nombre2 :
        indEgal = true
        break;
    default:
        break;
    }



}