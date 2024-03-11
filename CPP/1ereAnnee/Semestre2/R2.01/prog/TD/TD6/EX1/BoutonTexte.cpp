#include "BoutonTexte.h"

BoutonTexte::BoutonTexte()
{
    Bouton();
    (*this).m_texte = new char[strlen("sans texte") + 1];
    strcpy((*this).m_texte, "sans texte");
}

BoutonTexte::BoutonTexte(const BoutonTexte &autre)
{
    Bouton(autre);
    (*this).m_texte = new char[strlen(autre.m_texte) + 1];
    strcpy((*this).m_texte, autre.m_texte);
}

BoutonTexte::BoutonTexte(const Bouton &b, const char *texte)
{
    Bouton(b);
    (*this).m_texte = new char[strlen(texte) + 1];
    strcpy((*this).m_texte, texte);
}

BoutonTexte::~BoutonTexte()
{
    delete m_texte;
}

void BoutonTexte::definirTexte(const char *texte)
{
    delete [] (*this).m_texte;
    (*this).m_texte = new char[strlen(texte) + 1];
    strcpy((*this).m_texte, texte);
}

void BoutonTexte::afficher(Fenetre &f) const
{
}

void BoutonTexte::effacer(Fenetre &f) const
{
}
