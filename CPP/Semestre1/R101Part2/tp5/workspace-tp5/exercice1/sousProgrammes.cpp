#include "sousProgrammes.h"
#include "fichierTexte.h"
#include <iostream>
using namespace std;

void afficherFichierTexte(string nomSysFic)
{
	UnFichierTexte fic;
	string ligne;
	bool fdf;

	associer(fic, nomSysFic);
	ouvrir(fic, consultation);
	while (true)
	{
		lireLigne(fic, ligne, fdf);
		if (fdf == true)
		{
			break;
		}
		cout << ligne << endl;
	}
	fermer(fic);
}

void etendreFichierTexte(string nomSysFicSource, string nomSysFicCible)
{
	UnFichierTexte fic1;
	UnFichierTexte fic2;
	string ligne;
	bool fdf;

	associer(fic1, nomSysFicSource);
	associer(fic2, nomSysFicCible);
	ouvrir(fic1, extension);
	ouvrir(fic2, extension);
	while (true)
	{
		ecrireLigne(fic1, ligne);
		if (fdf == true)
		{
			break;
		}
		
	}
	fermer(fic1);
	fermer(fic2);
}

void viderFichierTexte(string nomSysFic)
{
	// Exemple du cours
	cout << "Exemple du cours e recopier..." << endl;
}