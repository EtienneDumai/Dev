#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

// contient la définition du type File implémentée à l'aide de 2 piles d'entiers non signés
// ainsi que les déclarations des primitives habituelles de gestion de cette file

#include "pile.h"
using namespace std;

struct File
{
    UnePile tete;
    UnePile queue;
};

// Primitives de gestion d'une telle File 

void initialiser (File& f);
// Initialise ou reinitialise une file vide prete a l'emploi

bool estVide (const File& f); 
// Retourne vrai si la file f est vide, faux sinon

unsigned int taille (const File& f);
// Retourne le nombre d'elements stockes dans la file f

void enfiler (File& f, UnElement e);
// Ajoute l'element e en queue de la file f

void defiler (File& f);
/* Retire l'element situe en tete de la file f
   Genere l'exception "fileVide" si la file f est vide */

void defiler (File& f, UnElement& e);
/* Retire l'element situe en tete de la file f et le stocke dans e
   Genere l'exception "fileVide" si la file f est vide */

UnElement premier (const File& f);
/* Retourne l'element situe en tete de la file f
   Genere l'exception "fileVide" si la file f est vide */


#endif
