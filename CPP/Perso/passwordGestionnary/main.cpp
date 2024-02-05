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
void consultationDuFichier(UnFichierTexte &fic, UnModeOuverture modeDouvertureDuFichier, string nomSys);
void modificationDuFichier(UnFichierTexte &fic, UnModeOuverture modeouvertureFichier, string nomSys = "fichier.txt");
// CORPS DU MAIN
#define DEBUG_ON = true

int main()
{

#define DEBUG_ON = true
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    choixModeOuverture(modeOuverture);
    ouvertureDuFichier(fichier, modeOuverture);
    return 0;
}

void choixModeOuverture(UnModeOuverture &modeOuvertureFichier)
{
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
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
    case 'm':
        modeOuvertureFichier = modification;
        break;
    default:
        break;
    }
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
}

void ouvertureDuFichier(UnFichierTexte &fichiertexte, UnModeOuverture modeOuvertureFichier, string nomSys)
{
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    if (modeOuvertureFichier == consultation)
    {
#ifdef DEBUG_ON
        cout << "INIT : " << __LINE__ << endl;
#endif
        consultationDuFichier(fichiertexte, modeOuvertureFichier, nomSys);
    }
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    if (modeOuvertureFichier == modification)
    {
#ifdef DEBUG_ON
        cout << "INIT : " << __LINE__ << endl;
#endif
        modificationDuFichier(fichiertexte, modeOuvertureFichier, nomSys);
    }
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
}

void consultationDuFichier(UnFichierTexte &fic, UnModeOuverture modeDouvertureDuFichier, string nomSys)
{
    associer(fic, nomSys);
    ouvrir(fic, modeDouvertureDuFichier);
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
            trouve = true;
            break;
        }
        if (fdf == true && trouve == false)
        {
            cout << "la plateforme que vous avez saisie n'a pas ete trouve veuillez verifier l'orthographe ou enrgistrer le mot de pass dans l'application" << endl;
            break;
        }
    }
    fermer(fic);
}

void modificationDuFichier(UnFichierTexte &fic, UnModeOuverture modeOuvertureDuFichier, string nomSys)
{
#ifdef DEBUG_ON
    cout << "INIT : " << __LINE__ << endl;
#endif
    bool enregistre = false;
    string reponsePlateforme;
    string identifiant;
    string password;
    associer(fic, nomSys);
    ouvrir(fic, modeOuvertureDuFichier);
    while (enregistre != true)
    {
        cout << "Quelle est le nom de la plateforme que vous voulez entrer vos informations de connexions (veuillez supprimer les espace exemple : SansEspace)" << endl;
        cin >> reponsePlateforme;
        ecrireLigne(fic, reponsePlateforme);
        cout << "Quel est votre identifiant pour la plateforme : " << reponsePlateforme << endl;
        cin >> identifiant;
        ecrireLigne(fic, identifiant);
        cout << "Quel est le mot de passe qui est lie a l'identifiant : " << identifiant << endl;
        cin >> password;
        ecrireLigne(fic, password);
        enregistre = true;
    }
}
