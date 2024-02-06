/**  MODULE Personne
     contient la définition du type Personne
     -------------------------------------------

 Date de dernière modification : 17/11/2023
 Auteur : Pantxika Dagorret
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/
#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
using namespace std;

// Définition des types du module
struct Adresse 
{
    string numRue; 
    string nomRue;
    unsigned short int codePostal;
    string nomVille; 
};

struct Personne
{
    string nom;
    string prenom;
    Adresse adresse;
};

// Primitives d'Entrée-Sortie
void afficher(const Personne& personne);
// Affiche sur une ligne le contenu de l'enregistrement passé en paramètre

#endif // PERSONNE_H