/* afficherInverseFichierTexte
   But : afficher à l'écran le contenu d'une liste d'entiers.
         Tester le parcours complet de liste en utilisant les primitives d'accès séquetiel et direct.
   Date : 14/01/2024
   Auteur : Pantxika Dagorret
   Remarque : Codage exercice 1 de la feuille de  TD n°7 - R1.01
*/
#include <iostream>
#include "liste.h" // configurée pour manipuler des listes d'entiers (int)
using namespace std;

/* Déclaration des sous-programmes */

void afficherSequentiel(UneListe &pListe);
/* affiche le contenu de la liste pListe, et la laisse la liste dans l'état initial
   Utilise les primitives d'accès séquentiel */

void afficherDirect(UneListe &pListe);
/* affiche le contenu de la liste pListe, et la laisse la liste dans l'état initial
   Utilise les primitives d'accès direct */

/* MAIN
   -------------------------*/

int main()
{
   // Déclaration et initialiatin d'un élément de type UneListe
   UneListe maListe;
   initialiser(maListe);

   // Ajout d'éléments dans la liste
   insererFin(maListe, 10);
   insererFin(maListe, 20);
   insererFin(maListe, 30);
   insererFin(maListe, 40);
   insererFin(maListe, 50);
   insererFin(maListe, 60);
   insererFin(maListe, 70);
   insererFin(maListe, 80);

   /* AfficherAvant - séquentiel */
   cout << "Affichage liste - utilisation primitives d'acces sequentiel " << endl;
   afficherSequentiel(maListe);

   cout << endl;

   /* AfficherAvant - direct */
   cout << "Affichage liste - utilisation primitives d'acces direct " << endl;
   afficherDirect(maListe);

   return 0;
}

/* Corps des sous-programmes
   -------------------------*/

void afficherSequentiel(UneListe &pListe)
{
   cout << "afficherSequentiel() en travaux..." << endl;
   allerDebut(pListe);
   while (parcoursEnCours(pListe) == true)
   {
      cout << elementCourant(pListe) << "  ";
      avancer(pListe);
   }
}

void afficherDirect(UneListe &pListe)
{
   int laTaille;
   laTaille=taille(pListe);
   for (int i = 1; i <= laTaille; i++)
   {
      allerEn(pListe, i);
      cout<<elementCourant(pListe)<<"  ";
   }
   
   cout << "afficherDirect() en travaux..." << endl;

}