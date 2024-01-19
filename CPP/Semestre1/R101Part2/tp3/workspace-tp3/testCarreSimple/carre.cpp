#include "carre.h"
#include <iostream>
using namespace std;

int getAbscisse(Carre pCarre)
{
    return pCarre.abscisse;
}

int getOrdonnee(Carre pCarre)
{
    return pCarre.ordonnee;
}

unsigned int getCote(Carre pCarre)
{
    return pCarre.cote;
}

void setAbscisse(Carre &pCarre, int valAbscisse)
{
    pCarre.abscisse = valAbscisse;
}

void setOrdonnee(Carre &pCarre, int valOrdonnee)
{
    pCarre.ordonnee = valOrdonnee;
}

void setCote(Carre &pCarre, unsigned int valCote)
{
    pCarre.cote = valCote;
}

bool toucher(Carre pCarre1, Carre pCarre2)
{
    bool verifToucher = false;
    if (pCarre1.abscisse == pCarre2.abscisse)
    {
        verifToucher = true;
    }
    else if (pCarre1.ordonnee == pCarre2.ordonnee)
    {
        verifToucher = true;
    }
    else
    {
        verifToucher = false;
    }
    return verifToucher;
}

bool toucherCoinCarre1(Carre pCarre1, Carre pCarre2, int valAbscisseCarre1, int valOrdonneeCarre1, unsigned int valCote1,
                       int valAbscisseCarre2, int valOrdonneeCarre2, unsigned int valCote2)
{
    bool verifToucherCoin = false;
    if (valAbscisseCarre1 == valAbscisseCarre2)
    {
        verifToucherCoin = true;
    }
    else if (getAbscisse(pCarre1)-valCote1 == valAbscisseCarre2)
    {
        verifToucherCoin=true;
    }
    else if (getOrdonnee(pCarre1)-valCote1==valAbscisseCarre2)
    {
        verifToucherCoin=true;
    }
    return verifToucherCoin;
}

bool estEgal(Carre pCarre1, Carre pCarre2)
{
    bool verifToutLesChamps = false;
    if (getAbscisse(pCarre1) == getAbscisse(pCarre2) && getOrdonnee(pCarre1) == getOrdonnee(pCarre2) && getCote(pCarre1) == getCote(pCarre2))
    {
        verifToutLesChamps = true;
    }
    else
    {
        verifToutLesChamps = false;
    }
    return verifToutLesChamps;
}

void init(Carre &pCarre, int valAbscisse, int valOrdonnee, unsigned int valCote)
{
    setAbscisse(pCarre, valAbscisse);
    setOrdonnee(pCarre, valOrdonnee);
    setCote(pCarre, valCote);
}

void init(Carre &pCarre, Carre pModele)
{
    pCarre.abscisse = pModele.abscisse;
    pCarre.ordonnee = pModele.ordonnee;
    pCarre.cote = pModele.cote;
}

void deplacerVers(Carre &pCarre, Carre pModele)
{
    pCarre.abscisse = pModele.abscisse;
    pCarre.ordonnee = pModele.ordonnee;
}

void deplacerVers(Carre &pCarre, int pNouvelleAbscisse, int pNouvelleOrdonnee)
{
    pCarre.abscisse = pNouvelleAbscisse;
    pCarre.ordonnee = pNouvelleOrdonnee;
}

void decalerDe(Carre &pCarre, int pDecalageAbscisse, int pDecalageOrdonnee)
{
    pCarre.abscisse += pDecalageAbscisse;
    pCarre.ordonnee += pDecalageOrdonnee;
}

void redimensionner(Carre &pCarre, float pFacteur)
{
    pCarre.cote = pCarre.cote * pFacteur;
}

void afficher(Carre pCarre)
{
    cout << "Abscisse du carre = " << pCarre.abscisse << endl;
    cout << "Ordonnee du carre = " << pCarre.ordonnee << endl;
    cout << "Cote du carre = " << pCarre.cote << endl;
}
