#include "Bouton.h"

//constructeur par défaut
Bouton::Bouton():
    m_cercle(),
    m_estActif(false){
}
//constructeur permettant de créer à partir d'un cercle et d'un etat
Bouton::Bouton(const Cercle &unCercle, bool estActif):
    m_cercle(unCercle),
    m_estActif(estActif){
}
//constructeur de copie
Bouton::Bouton(const Bouton &unBouton):
    m_cercle(unBouton.m_cercle),
    m_estActif(unBouton.m_estActif){
}
void Bouton::definir(int x, int y, int rayon, int r, int v, int b, bool estActif)
{
    (*this).m_cercle.placer(x, y);
    (*this).m_cercle.dimensionner(rayon);
    (*this).m_cercle.definirCouleur(r,v,b);
    (*this).m_estActif=estActif;
}

void Bouton::definir(int x, int y, int rayon, Couleur coul, bool estActif)
{
    (*this).definir(x,y,rayon, uneCouleur.rouge(), uneCouleur.vert(), uneCouleur.bleu(), estActif);
}

void Bouton::activer(bool estActif)
{
    (*this).m_estActif = true;
}

void Bouton::desactiver(bool estActif)
{
    (*this).m_estActif = false;
}

bool Bouton::actif() const
{
    return (*this).m_estActif;
}

int Bouton::coordX() const
{
    return (*this).m_cercle.coordX();
}

int Bouton::coordY() const
{
    return (*this).m_cercle.coordY();
}

int Bouton::rayon() const
{
    return (*this).m_cercle.rayon();
}

Couleur Bouton::couleur() const
{
    return Couleur();
}

void Bouton::definirCouleur(Couleur uneCouleur)
{
    (*this).m_cercle.definirCouleur(uneCouleur);
}

void Bouton::afficher(Fenetre &f) const
{*
    (*this).m_cercle.afficher(f);
    if ((*this).actif())
    {
        f.choixCouleurTrace((*this).couleur());
        int r = (*this).rayon();
        int x = (*this).coordX()-r/2;
        int y = (*this).coordY()-r/2;
        f.remplitEllispe(x,y,r,r);
    }
    
}

void Bouton::effacer(Fenetre &f) const
{
    (*this).m_cercle.effacer(f);
    (*this).dessinerEtat(f, f.couleurFond());
}

bool Bouton::touche(int x, int y) const
{
    return (*this).m_cercle.touche(x,y);
}
