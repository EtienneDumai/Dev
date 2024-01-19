/**
 * Fichier : carre.h
 * But : Interface du module Carre implémentant le Type Abstrait de Données (TAD) Carre
 * Auteur : Dumai Etienne
 * date : 05 décembre 2023
 * Référence : feuille de TD n°3, exercice 2
 */
#ifndef CARRE_H
#define CARRE_H
#include "point.h"
struct Carre
{
    Point origine;
    unsigned int cote;
};

/*    Getters et setters (accès et Modification partielle et globale) de l'enregistrement*/
int getAbscisse(Carre pCarre);
int getOrdonnee(Carre pCarre);
unsigned int getCote(Carre pCarre);
int getOrigine(const Carre &pCarre);
/* But : retourne respectivement abscisse, ordonnée de l'origine du carre pCarre, puis cote du carre*/

void setAbscisse(Carre &pCarre, int valAbscisse);
void setOrdonnee(Carre &pCarre, int valOrdonnee);
void setCote(Carre &pCarre, unsigned int valCote);
void setOrigine(Carre &pCarre, Point origine);
/* But : Affecte la valeur du second paramètre au champ correspondant du paramètre pCarre */

/*    Primitives de comparaison*/

bool toucher(Carre pCarre1, Carre pCarre2);
bool toucherCoin(Carre pCarre1, Carre pCarre2);
/* But : retourne true si les 2 carrés se touchent ou se superposent, false sinon) */

bool estEgal(Carre pCarre1, Carre pCarre2);
/* Retourne true si tous les champs de pCarre1 et pCarre2 sont égaux (même origine, même cote)*/

/*    Modificateurs Initialisations*/

void init(Carre &pCarre, int valAbscisse, int valOrdonnee, unsigned int valCote);
/* But : initialise tous les champs du paramèetre pCarre avec les paramèters qui suivent */

void init(Carre &pCarre, const Point origine, unsigned int valCote);

void init(Carre &pCarre, Carre pModele);
/* But : initialise tous les champq du paramètre pCarre à partir des champs du paramètre PModele */

void deplacerVers(Carre &pCarre, Point& pPoint);

void deplacerVers(Carre &pCarre, Carre pModele);
/* But : place l'origine du carré pCarre sur l'origine du carre pModele */

void deplacerVers(Carre &pCarre, int pNouvelleAbscisse, int pNouvelleOrdonnee);
/* But : place l'origine du carré au point d'abscisse pNouvelleAbscisse et d'ordonnée pNouvelleOrdonnee */

void decalerDe(Carre &pCarre, int pDecalageAbscisse, int pDecalageOrdonnee);
/* But : deplace l'origine du carré vers le point {abscisse+pDecalageAbscisse, ordonnee+pDecalageOrdonnee} */

void redimensionner(Carre &pCarre, float pFacteur);
/* But : multiplie la taille du carré par le paramètre pFacteur, qui doit être > 0.0 */

/*    Entrés / Sorties */

void afficher(Carre pCarre);
/* But : affiche à l'écran le contenu du carré pCarre */

#endif