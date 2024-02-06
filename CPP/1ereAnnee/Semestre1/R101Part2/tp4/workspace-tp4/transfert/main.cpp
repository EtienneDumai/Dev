/* Transfert
   But : transferts de contenus entre piles et files.
   Date : 08/12/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage des exercices de la feuille de TD n°4 - R1.01
*/
#include <iostream>
using namespace std;
#include "file.h"
#include "pile.h"

/* Déclarations des sous-programmes
-----------------------------------*/

void afficher(UnePile &pPile);
// affiche le contenu de la pPile et la restitue en l'état

void afficher(UneFile &pFile);
// affiche le contenu de la pFile et la restitue en l'état

void remplirContenant(unsigned int nbValeurs, UnePile &pPile);
// But : empile sur pPile les nbValeurs premiers entiers

void transfertContenu(UnePile &pSource, UnePile &pDestination);
// But : tranfere le coteu de pISource vers pDestination

void testAfficherPile();
void testAfficherFile();
// But tester les sous-programmes d'affichage d'une Pile et File

void testTransferts_executionsABC();
// But : Programme de test pour l'exercice n°3 de la feuille de TD n°6

int main()
{
   //testAfficherPile();
   testAfficherFile();
   //  testTransferts_executionsABC();
   return 0;
}

/* Corps des sous-programmes
----------------------------*/

void afficher(UnePile &pPile)
{
   UnePile pileTemp;
   while (estVide(pPile) != true)
   {
      cout << sommet(pPile) << endl;
      empiler(pileTemp, sommet(pPile));
      depiler(pPile);
   }
   while (estVide(pileTemp) != true)
   {
      empiler(pPile, sommet(pileTemp));
      depiler(pileTemp);
   }
}

void afficher(UneFile &pFile)
{
   int lgFile;
   lgFile = taille(pFile);
   cout<<"ICI";
   for (int i = 1; i > lgFile; i++)

   {
      afficher(premier(pFile));
      enfiler(pFile, premier(pFile));
      defiler(pFile);
   }
}

void remplirContenant(unsigned int nbValeurs, UnePile &pPile)
{
}
void transfertContenu(UnePile &pSource, UnePile &pDestination)
{
}

void testAfficherPile()
{

   // Déclaration et initialisation de la pile
   UnePile maPile;
   initialiser(maPile);

   // Ajout d'éléments dans la pile
   empiler(maPile, 0);
   empiler(maPile, 1);
   empiler(maPile, 2);
   empiler(maPile, 3);
   empiler(maPile, 4);
   empiler(maPile, 5);

   afficher(maPile);
}

void testAfficherFile()
{
      //Déclaration et initialisation de la file
       UneFile maFile;
       initialiser(maFile);

       // Ajout d'éléments dans la pile
       enfiler(maFile, 0); enfiler(maFile, 1);
       enfiler(maFile, 2); enfiler(maFile, 3);
       enfiler(maFile, 4); enfiler(maFile, 5);

       afficher(maFile);
}

void testTransferts_executionsABC()
{

   const unsigned int NB_VALEURS = 4;
   UnePile pile_1; // contenant_1
   UnePile pile_2; // contenant_2
   UneFile file_1; // contenant_1
   UneFile file_2; // contenant_2

   /* ------------------   trouverLeContenant : exécution_A, avec :
      contenant_1 : pile
      contenant_2 : pile
   ----------------------------------------------------------------*/
   /*
   cout << "execution A " << endl;
   // initialisations >> pile_1, pile_2
   initialiser (pile_1);
   initialiser (pile_2);
   // pile_1 (vide) >> remplir Contenant >> pile_1
   remplirContenant(NB_VALEURS, pile_1);
   // pile_1, pile_2 (vide) >> transfertContenu >> pile_1 (vide), pile_2
   transfertContenu (pile_1, pile_2);
   // pile_2 >> affichage
   afficher(pile_2);
   */

   /* --------------------   trouverLeContenant : exécution_B, avec :
      contenant_1 : file
      contenant_2 : pile
      ----------------------------------------------------------------*/
   /*
   cout << "execution B " << endl;
   // initialisations >> file_1, pile_2
   initialiser (file_1);
   initialiser (pile_2);
   // file_1 (vide) >> remplir Contenant >> file_1
   remplirContenant(NB_VALEURS, file_1);
   // file_1, pile_2 (vide) >> transfertContenu >> file_1 (vide), pile_2
   transfertContenu (file_1, pile_2);
   // pile_2 >> affichage
   afficher(pile_2);
   */

   /* --------------------   trouverLeContenant : exécution_C, avec :
       contenant_1 : pile
       contenant_2 : file
       ----------------------------------------------------------------*/
   /*
    cout << "execution C " << endl;
   // initialisations >> pile_1, file_2
   initialiser (pile_1);
   initialiser (file_2);
    // pile_1 (vide) >> remplir Contenant >> pile_1
   remplirContenant(NB_VALEURS, pile_1);
   // pile_1, file_2 (vide) >> transfertContenu >> pile_1 (vide), file_2
   transfertContenu (pile_1, file_2);
   // file_2 >> affichage
   afficher(file_2);
   */
}