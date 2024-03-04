#include <iostream>
#include "game-tools.h"

int nbToGuess;
int nbGuessed;
int nbRangeRandom;
string bonneReponse = "Bravo, vous avez trouve le nombre a deviner !";
string tropGrand = "Le nombre a deviner est plus petit.";
string tropPetit = "Le nombre a deviner est plus grand.";

int main()
{
    cout<<"Entrez la valeur maximale pour le nombre a deviner : ";
    cin>>nbRangeRandom;
    nbToGuess=random(1, nbRangeRandom);
    while (true)
    {
        cout<<"Entrez le nombre a deviner : ";
        cin>>nbGuessed;
        if (nbGuessed<nbToGuess)
        {
            afficherTexteEnCouleur(tropPetit, bleu, true);
        }
        else if (nbGuessed>nbToGuess)
        {
            afficherTexteEnCouleur(tropGrand, rouge, true);
        }
        else if (nbGuessed==nbToGuess)
        {
            afficherTexteEnCouleur(bonneReponse, vert, true);
            break;
        }
        
    }
    
    return 0;
}