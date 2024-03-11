#include "BoutonTexte.h"

BoutonTexte::BoutonTexte()
{
    Bouton();
    (*this).m_texte = new char[strlen("sans texte") + 1];
    strcpy((*this).m_texte, "sans texte");
}

BoutonTexte::BoutonTexte(const BoutonTexte &autre)
{
    m_texte = autre.m_texte;
    Bouton(autre);
}

BoutonTexte::BoutonTexte(const Bouton &b, const char *texte)
{
    m_texte(texte);
    Bouton(b);
}

BoutonTexte::~BoutonTexte()
{
    delete m_texte;
}

void BoutonTexte::definirTexte(const char *texte)
{

}

void BoutonTexte::afficher(Fenetre &f) const
{
}

void BoutonTexte::effacer(Fenetre &f) const
{
}
