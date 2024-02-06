/*
 Programme : Validation d'un module d'enseignement
 But :  Déterminer si un élève valide son enseignement
 Date de dernière modification : 20 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;


int main(void)
{
     // VARIABLES
    double Note1Coef1; // Nombre auquel on doit donner le signe
    double Note2Coef2;
    double Coef1=1;
    double Coef2=2;
    double Moy;

     // TRAITEMENTS
    // clavier >> Saisir la valeur de la premiere note >> Note1Coef1
    
    cout << "Valeur de la premiere note : ";
    cin >> Note1Coef1; 

    // clavier >> Saisir la valeur de la premiere note >> Note2Coef2

    cout << "Valeur de la deuxieme note : ";
    cin >> Note2Coef2;

    //Calcul de la moyenne des 2 notes

    Moy= ((Note1Coef1)*Coef1+(Note2Coef2)*Coef2)/(Coef1+Coef2);

    //Détérmination du résultat et du passage

    if (Moy >= 10)
        cout << "Vous etes recu, votre moyenne est de : " << Moy << endl;
    else
    {
        cout << "Votre moyenne est trop faible, vous n'etes pas recu" << endl;
    }
    return 0;



}