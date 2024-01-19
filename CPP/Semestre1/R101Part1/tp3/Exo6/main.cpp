/*
 Programme : Calculette
 But :  Faire une calculatrice
 Date de dernière modification : 19 septembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;


int main(void)
{
     // VARIABLES
    double val1; // nombre assigné a la valeur 1
    double val2; // nombre assigné a la valeur 2
    char oper; // opérateur pour l'opération a faire
    bool divParZero=false; // test pour savoir si la division se fait par zero
    bool opInvalide=false; // test pour savoir si l'operateur saisie est correct
    double resultat; // résultat de l'operation entre val1 et val2

    // TRAITEMENT
    // clavier >> Saisir la valeur de valeur 1 >> val1

    cout << "Quel est la valeur %d \ndu nombre 1 ? \n",3; //<< endl;
    cin >> val1;

     // clavier >> saisir l'operateur >> oper
    cout << "Quel est l'operateur ?" << endl;
    cin >> oper;

    // clavier >> Saisir la valeur de valeur 2 >> val2

    cout << "Quel est la valeur du nombre 2 ?" << endl;
    cin >> val2;
    
   

    switch (oper)
    {
    case '+':
        resultat = val1+val2;
        break;
    case '-':
        resultat=val1-val2;
        break;
    case '*':
        resultat=val1*val2;
        break;
    case '/':
        if (val2 != 0)
        {
            resultat=val1 / val2;
        }
        else
        {
            divParZero = true;
        }
        break;
    default:
        opInvalide = true;
        break;
    }
    if (opInvalide == true)
    {
        cout << "Operation sasie incorrecte" << endl;
    }
    else
    {
        if (divParZero == true)
        {
            cout << "Division par zero impossible" << endl;
        }
        else
        {
            cout << "Le resultat du calcul est " << resultat << endl;
        }
        
    }
    
    
}