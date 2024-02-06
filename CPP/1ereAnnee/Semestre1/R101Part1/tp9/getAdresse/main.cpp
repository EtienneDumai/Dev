/*
 Programme : getAdressse
 But : Faire une fonction qui retourne une adresse de client en fonction du client choisi
 Date de dernière modification : 07 novembre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

struct Adresse //Enregistrement
{
    string numRue = "2 bis";                 // par exemple "2 bis"
    string nomRue = "alle du parc Montaury"; // par exemple "alle du parc Montaury"
    unsigned int codePostal = 64600;         // par exemple 64600
    string ville = "Anglet";                 // par exemple Anglet
};
struct Personne
{
    string nom;      // Le nom de la personne
    string prenom;   // le prénom de la personne
    Adresse adresse; // l'adresse de la personne
};

Adresse getAdresse(const Personne &personneP);

int main(void)
{
    Adresse resultatA;
    Personne client;
    resultatA = getAdresse(client);
    cout << resultatA.numRue << " " << resultatA.nomRue << " " << resultatA.codePostal << " " << resultatA.ville;
    Adresse adresseClient;
    adresseClient = getAdresse(client);
}
Adresse getAdresse(const Personne &personneP) //Défintion de la fonction 
{
    return personneP.adresse;
}