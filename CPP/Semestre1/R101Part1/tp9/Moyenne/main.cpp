/*
 Programme : Moyenne
 But : Creer une fonction qui retourne une moyenne à partir d'un tableau
 Date de dernière modification : 09 novembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

float moyenne(const float tab[], unsigned int nbCases);
// BUT : retourne la moyenne des valeurs du tableau tab de longueur nbCases

int main(void)
{
    float valMoyenne;
    unsigned int nbCases;
    cout << "Combien de note vont servir a calculer la moyenne"<<endl;
    cin >> nbCases;
    float note[nbCases];
    for (size_t i = 0; i <= (nbCases-1); i++)
    {
        cout<<"Quel est la valeur de la note que vous voulez rentrer ?"<<endl;
        cin>>note[i];
    }
    valMoyenne=moyenne(note,nbCases);
    cout<< "La moyenne des notes du tableau est egal a "<< valMoyenne<<endl;
}

float moyenne(const float tab[], unsigned int nbCases)
{
    float somme=0;
    for (size_t i = 0; i <= (nbCases-1); i++)
    {
        somme+=tab[i];
    }
    return (somme/nbCases);

}