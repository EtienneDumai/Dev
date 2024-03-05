#include "Bouton.h"

Bouton::Bouton(const Bouton &autre)
{
    Cercle(autre);
    m_estActif(autre.m_estActif);
}

Bouton::Bouton()
{
    Cercle();
    m_estActif(false);
}

Bouton::Bouton(const Cercle &c, bool etat)
{
    Cercle(c);
    m_estActif(etat);
}

void Bouton::definir(int x, int y, int rayon, int rouge, int vert, int bleu, bool etat)
{
    (*this).placer(x, y);
    (*this).dimensionner(rayon);
    (*this).definirCouleur(rouge, vert, bleu);
    (*this).m_estActif = etat;
}

void Bouton::definir(int x, int y, int rayon, const Couleur &couleur, bool etat)
{
    (*this).definir(x, y, rayon, couleur.rouge(), couleur.vert(), couleur.bleu(), etat);
}

void Bouton::activer(bool etat)
{
}

void Bouton::desactiver(bool etat)
{
}

bool Bouton::actif() const
{
}

int Bouton::coordX() const
{
}

int Bouton::coordY() const
{
}

int Bouton::rayon() const
{
}

Couleur Bouton::couleur() const
{
}

void Bouton::definirCouleur(Couleur couleur)
{
}

void Bouton::afficher(Fenetre &f, Couleur c) const
{
    (*this).Cercle::afficher(f);
    (*this).dessinerEtat(f, (*this).couleur());
}

void Bouton::effacer(Fenetre &f, Couleur c) const
{
    (*this).Cercle::effacer(f);
    (*this).dessinerEtat(f, (*this).couleur());
}

bool Bouton::touche(int x, int y) const
{
}
