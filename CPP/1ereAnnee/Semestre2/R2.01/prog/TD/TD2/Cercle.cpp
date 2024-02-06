#include "Cercle.h"

void Cercle::placer(int x, int y)
{
    (*this).m_x = x;
    (*this).m_y = y;
}

void Cercle::definirCouleur(int r, int v, int b)
{
    (*this).m_couleur.definir(r,v,b);//.definir vient des primitives du TD0

}

void Cercle::definirCouleur(const Couleur &uneCouleur)
{
    (*this).m_couleur=uneCouleur;
}

Couleur Cercle::couleur() const
{
    return (*this).m_couleur;
}

void Cercle::afficher(Fenetre &f) const
{
    int r= (*this).m_rayon;
    f.choisirCouleurTrace((*this).m_couleur);
    f.traceArc((*this).coordX()-r,(*this).coordY(),2*r,2*r);
}

void Cercle::effacer(Fenetre &f) const
{
    (*this).couleur=(*this).couleurFond;
}

bool Cercle::touche(int x, int y) const
{
    return (x-(*this).m_x)*(x-(*this).m_x)+(y-(*this).m_y)*(y-(*this).m_y);
}
