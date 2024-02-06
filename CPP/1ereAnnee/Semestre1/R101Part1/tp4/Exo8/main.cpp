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
    int valArretNote = 999;
    double sommeDesNotes;
    int nbDeNotes;
    double valSaisie;
    double moyenne;
    //TRAITEMENT
    nbDeNotes = 0;
    sommeDesNotes = 0;
    
    while (true)
    {
    
        cout << "Entrez la note: " << endl;
        cin >> valSaisie;
        if (valSaisie == valArretNote)
        {
            break;
        }
        if (valSaisie>=0 && valSaisie<=20)
        {
            sommeDesNotes += valSaisie;
            nbDeNotes +=1;
        }
        else
        {
            cout << "Valeur saisie incorrect" << endl;
        }
       
        
        
    }
     if (nbDeNotes>0)
        {
            moyenne = sommeDesNotes / nbDeNotes;
        }
    if (nbDeNotes>0)
    {
        cout <<"Votre moyenne est de : " << moyenne << endl;
    }
    else
    {
        cout << "Impossible de calculer la moyenne";
    }
    
    
    return 0;

}