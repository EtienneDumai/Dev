#include <iostream>
#include <sstream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

float moyennePluviometrique(string nomSysFic)
{
    UnFichierTexte fic;
    int somme = 0;
    int nbValeur = 0;
    bool fdf;
    int valeur;
    float moyennePluviometre;
    associer(fic, nomSysFic);
    ouvrir(fic, consultation);

    while (true)
    {
        lireMot(fic, valeur, fdf);
        if (fdf == true)
        {
            break;
        }
        somme += valeur;
        nbValeur += 1;
    }
    fermer(fic);
    moyennePluviometre = somme / nbValeur;

    return moyennePluviometre;
}
