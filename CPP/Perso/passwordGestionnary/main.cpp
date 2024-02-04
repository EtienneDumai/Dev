/**
 * @file main.cpp
 * @author Dumai Etienne
 * @brief Gestionnaire de mot de passe non encryptées
 * @date 2024-02-03
 */

// IMPORTATION DES MODULES ET DES BIBLIOTHEQUES

#include <iostream>
#include "fichierTexte.h"
#include "pile.h"
using namespace std;

// D2CLARATION DES VARIABLES
UnFichierTexte fichier;
UnModeOuverture modeOuverture;
char modeDouvertureDuFichier;
string nomSystemeficSource; // nom système du fichier à consulter
// DECLARATION DES SOUS PROGRAMMES

void choixModeOuverture(UnModeOuverture& modeOuvertureFichier);
void modificationDuFichier(UnFichierTexte fic, UnModeOuverture modeOuvertureFichier, string nonSys="fichier.txt");
    // CORPS DU MAIN

    int main()
{
    return 0;
}

void choixModeOuverture(UnModeOuverture& modeOuvertureFichier)
{
    char reponseMode;
    cout << "Quel est votre mode d'ouverture" << endl;
    cout << "c - consultation" << endl;
    cout << "a - creation" << endl;
    cout << "e - extension" << endl;
    cin >> reponseMode;
    switch (reponseMode)
    {
    case 'c':
        modeOuvertureFichier = consultation;
        break;
    case 'a':
        modeOuvertureFichier = creation;
        break;
    case 'e':
        modeOuvertureFichier = extension;
        break;
    default:
        break;
    }
}

void modificationDuFichier(UnFichierTexte fic, UnModeOuverture modeOuvertureFichier, string nonSys)
{
    associer(fic, nonSys);
    ouvrir(fic, modeOuvertureFichier);
    
}
