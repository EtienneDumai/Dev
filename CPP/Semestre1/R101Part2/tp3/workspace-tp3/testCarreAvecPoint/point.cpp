/**
 * Fichier : point.cpp
 * But : corps du module Point permettant du TAD Point
 * Auteur : Pantxika Dagorret
 * date : 24-11-2023
 * Référence : Feuille de TD n°3 - Exercice 2 
 */

#include "point.h"
#include <iostream>
using namespace std;
/* -------------------------------------------------------------------------------------------
   Getters et setters (accès et Modification individuelle) de chaque champ de l'enregistrement 
   -------------------------------------------------------------------------------------------*/ 
int getAbscisse (const Point& pPoint)
{
   return pPoint.abscisse;
}

int getOrdonnee (const Point& pPoint)
{
   return pPoint.ordonnee;
}

void setAbscisse (Point& pPoint, int pAbscisse)
{
   pPoint.abscisse = pAbscisse;
}
void setOrdonnee (Point& pPoint, int pOrdonnee)
{
   pPoint.ordonnee = pOrdonnee;
}

/* --------------
   Observateurs 
   -------------*/
bool estOriginePlan (const Point& pPoint)
{
   return (
            (getAbscisse(pPoint) == getAbscisse(ORIGINE_PLAN))
            &&
            (getOrdonnee(pPoint) == getOrdonnee(ORIGINE_PLAN))            
          );
}

/* --------------
   Modificateurs 
   --------------*/
void init (Point& pPoint, int pAbscisse, int pOrdonnee)
{
   setAbscisse(pPoint, pAbscisse);
   setOrdonnee(pPoint, pOrdonnee);
}

void init (Point& pPoint, const Point& pModele)
{
   setAbscisse(pPoint, getAbscisse(pModele));
   setOrdonnee(pPoint, getOrdonnee(pModele));
}

/* -------------------
   Entrées / Sorties 
   ------------------*/
   void afficher (const Point& pPoint)
   {
      cout << "{" << getAbscisse(pPoint) << "," << getOrdonnee(pPoint) << "}" ;
   }