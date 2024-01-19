#include "sousProgrammes.h"
//initialiser une file 
void initialiser(File &f)
{
    initialiser(f.tete);
    initialiser(f.queue);
}
//initialser une file avec une tete et une queue
void initialiser(File &f, File fExemple)
{
    f.tete = fExemple.tete;
    f.queue = fExemple.queue;
}
// vider une file
bool estVide(const File &f)
{
    return (estVide(f.tete) && estVide(f.queue));
}
//empiler une file
void enfiler(File &f, UnElement e)
{
    empiler(f.queue, e);
}
//enfiler une file
void defiler(File &f)
{
    // Variables locales
    UnElement temp;

    // Tentative de dépilage de la tête
    if (!estVide(f.tete))
    {
        depiler(f.tete);
    }
    // Sinon effectuer la transvasion
    else
    {
        while (!estVide(f.queue))
        {
            depiler(f.queue,temp);
            empiler(f.tete, temp);
        }
        depiler(f.tete);
    }
}
//defiler une file
void defiler(File &f, UnElement& e)
{
    // Variables locales
    UnElement temp;

    // Tentative de dépilage de la tête
    if (!estVide(f.tete))
    {
        depiler(f.tete, e);
    }
    // Sinon effectuer la transvasion
    else
    {
        while (!estVide(f.queue))
        {
            depiler(f.queue, temp);
            empiler(f.tete, temp);
        }
        depiler(f.tete, e);
    }
}