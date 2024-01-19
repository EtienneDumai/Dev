/*
 Programme : Foncion Valeur Absolue
 But : Faire une fonction qui retourne 
 Date de dernière modification : 07 novembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

double valAbsol(double nbr);//déclaration de la fonction
// BUT : retourner la valeur absolue du nombre nombre

int main(void)
{
    double valAbs; //Variable qui va prendre le résultat de la fonction
    double nombre; //Variable qui va être en paramètre de la fonction
    cout<<"quel est le nombre que vous voulez savoir la valeur absolue"<<endl;
    cin>>nombre; 
    valAbs = valAbsol(nombre); //Appel de la fonction
    cout<<"La valeur absolue de "<<nombre<<" est "<<valAbs<<endl; //AFfichage du résultat de la fonction
    return 0;
}

double valAbsol(double nbr) //Définition de la fonction
{
    return nbr > 0 ? nbr : -nbr;
}
