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

void choixModeOuverture(UnModeOuverture &modeOuvertureFichier);
void ouvertureDuFichier(UnFichierTexte &fichiertexte, UnModeOuverture modeOuvertureFichier, string nomSys = "fichier.txt");
void consultationDuFichier(UnFichierTexte &fic);
void modificationDuFichier(UnFichierTexte &fic, UnModeOuverture modeouvertureFichier, string nomSys = "fichier.txt");
// CORPS DU MAIN

int main()
{
    choixModeOuverture(modeOuverture);
    ouvertureDuFichier(fichier, modeOuverture);
    return 0;
}

void choixModeOuverture(UnModeOuverture &modeOuvertureFichier)
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

void ouvertureDuFichier(UnFichierTexte &fichiertexte, UnModeOuverture modeOuvertureFichier, string nomSys)
{
    associer(fichiertexte, nomSys);
    ouvrir(fichiertexte, modeOuvertureFichier);
    if (modeOuvertureFichier == consultation)
    {
        consultationDuFichier(fichiertexte);
    }
}

void consultationDuFichier(UnFichierTexte &fic)
{
    bool trouve = false;
    bool fdf;
    string mot;
    string plateformeDuMotDePasse;
    cout << "De quelle plateforme sur laquelle vous etes inscrit voulez-vous avoir "
         << "l'identifiant et le mot de passe ?" << endl;
    cin >> plateformeDuMotDePasse;
    while (true)
    {

        lireMot(fic, mot, fdf);
        if (mot == plateformeDuMotDePasse)
        {
            lireMot(fic, mot, fdf);
            cout << "Voici l'identifiant : " << mot << endl;
            lireMot(fic, mot, fdf);
            cout << "Voici le mot de passe du compte : " << mot << endl;
            trouve=true;
            break;
        }
        if (fdf == true && trouve==false)
        {
            cout << "la plateforme que vous avez saisie n'a pas ete trouve veuillez verifier l'orthographe ou enrgistrer le mot de pass dans l'application" << endl;
            break;
        }
    }
}

void modificationDuFichier(UnFichierTexte &fic, UnModeOuverture modeouvertureFichier, string nomSys)
{
}
