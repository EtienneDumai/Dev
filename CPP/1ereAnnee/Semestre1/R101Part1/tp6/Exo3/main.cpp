/*
 Programme : Représentation et manipulation de cartes a jouer
 But :  Faire le jeu de carte de la Bataille
 Date de dernière modification : 13 octobre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/


#include <iostream>
using namespace std;


int main(void)
{
    //VARIABLES
    //definition du type de Couleur et de Valeur
    enum Couleur{coeur,carreau,pique,trefle};
    enum Valeur{deux=2,trois=3,quatre=4,cinq=5,six=6,sept=7,huit=8,neuf=9,dix=10,valet=11,dame=12,roi=13,as=14};
    //definition du type de Carte
    struct Carte
    {
        Valeur val;//valeur de la carte
        Couleur coul;//Couleur de la carte

    };
    Carte carte1;
    carte1.val=dame;
    carte1.coul=trefle;
    Carte carte2;
    carte2.val=roi;
    carte2.coul=pique;
    Carte carteGagnante;
    bool carteEquivalente;

    //TRAITEMENT

    //Déterminer lka carte la plus forte
    carteEquivalente=false;
    if (carte1.val>carte2.val)
    {
        carteGagnante=carte1;
    }
    if (carte1.val<carte2.val)
    {
        carteGagnante=carte2;
    }

    //Afficher la carte la plus forte

    if (carteEquivalente== true)
    {
        cout<<"Les deux cartes sont de meme force";

    }
    else
    {
        //afficher la valeur de la carte
        switch (carteGagnante.val)
        {
        case valet:
            cout<<"Valet"<<endl;
            break;
        case dame:
            cout<<"dame"<<endl;
            break;
        case roi:
            cout<<"roi"<<endl;
            break;
        case as:
            cout<<"as"<<endl;
            break;
        default:
            cout<< carteGagnante.val;
            break;
        }
        //afficher la couleur de la carte
        switch (carteGagnante.coul)
        {
        case coeur:
            cout<<"coeur"<<endl;                   
            break;
        case carreau:
            cout<<"carreau"<<endl;
            break;
        case pique:
            cout<<"pique"<<endl;
            break;
        case trefle:
            cout<<"trefle"<<endl;
            break;
        }
    
    }
    

}