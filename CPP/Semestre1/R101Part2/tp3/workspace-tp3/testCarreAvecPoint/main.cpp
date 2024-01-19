/*
 * Fichier : main.cpp
 * But : Programme de test du module (TAD) Carre, où Carre utilise le module (TAD) Point
 * Auteur : Pantxika Dagorret
 * date : 24-11-2023
 * Référence : Feuille de TD n°3 - Exercice 2
 */
#include <iostream>
using namespace std;
#include "point.h"

/* ---- Déclarations de sous-Programmes utilisés par main() --------
-------------------------------------------------------------------*/
void test_estEgal(const Carre &pCarre1, const Carre &pCarre2);
// But : affiche le résultat de l'appel estEgal(pCarre1, pCarre2)

void test_toucher(const Carre &pCarre1, const Carre &pCarre2);
// But : affiche le résultat de l'appel toucher(pCarre1, pCarre2)

void test_action(string pLibelleAction, const Carre &pCarre, unsigned int pNum);
// affiche l'instruction exécutée (pLibelleAction) et le contenu du paramètre pCarre modifié par l'action

/*------------------------main() --------------------------
------------------------------------------------------------*/

int main(void)
{

	struct Carre
	{
		Carre carre1;
		Carre carre2;
	};

	// ORIGINE_PLAN, 10 >> init >> carre1   ---- NOUVEAU : UTILISATION CLASSE POINT
	init(carre1, ORIGINE_PLAN, 10);
	test_action("init (carre1, ORIGINE_PLAN, 10);", carre1, 1);

	// {18,18}, 10 >> init >> carre2        ---- NOUVEAU : UTILISATION CLASSE POINT
	init(carre2, {18, 18}, 10);
	test_action("init (carre2, {18, 18}, 10);", carre2, 2);

	// carre1, carre2 >> Observateurs >> (ecran)
	test_estEgal(carre1, carre2);

	// carre1, carre2 >> Observateurs >> (ecran)
	test_toucher(carre1, carre2);

	// carre1, 11 >> decalerDe >> carre1
	decalerDe(carre1, 12, 12);
	test_action("decalerDe (carre1, 12, 12);", carre1, 1);
	test_estEgal(carre1, carre2);
	test_toucher(carre1, carre2);

	decalerDe(carre1, -1, -1);
	test_action("decalerDe (carre1, -1, -1);", carre1, 1);
	test_estEgal(carre1, carre2);
	test_toucher(carre1, carre2);

	// carre1, 0.5 >> redimensionner >> carre1
	redimensionner(carre1, 0.5);
	test_action("redimensionner (carre1, 0.5);", carre1, 1);
	test_estEgal(carre1, carre2);
	test_toucher(carre1, carre2);

	// carre1, csg tq csg={13, 13} >> deplacerVers >> carre1        ---- NOUVEAU : UTILISATION CLASSE POINT
	Point csg;
	init(csg, 13, 13);
	deplacerVers(carre1, csg); // Question : pourquoi le compilateur n'accepte plus l'instruction deplacerVers (carre1, {13, 13});  ?
	test_action("Point csg; init (csg, 13, 13); deplacerVers (carre1, csg);", carre1, 1);
	test_estEgal(carre1, carre2);
	test_toucher(carre1, carre2);

	return 0;
}

/* ---- Corps des sous-Programmes de main() --------
----------------------------------------------------*/

void test_estEgal(const Carre &pCarre1, const Carre &pCarre2)
{
	if (estEgal(pCarre1, pCarre2))
	{
		cout << "Les 2 carres sont egaux " << endl;
	}
	else
	{
		cout << "Les 2 carres sont differents" << endl;
	};
}

void test_toucher(const Carre &pCarre1, const Carre &pCarre2)
{
	if (toucher(pCarre1, pCarre2))
	{
		cout << "Les 2 carres se touchent " << endl;
	}
	else
	{
		cout << "Les 2 carres NE se touchent PAS" << endl;
	};
}

void test_action(string pLibelleAction, const Carre &pCarre, unsigned int pNum)
{
	cout << endl;
	cout << pLibelleAction << endl;
	cout << "carre" << pNum << " : ";
	afficher(pCarre);
}
