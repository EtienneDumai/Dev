#include "Sportif.h"
#include "Outils.h"
Sportif::Sportif(string lePrenom, string leNom, int lAnneeNaissance)
{
    (*this).setNom(leNom);
    (*this)._prenom = lePrenom;
    this->setAnneeNaissance(lAnneeNaissance);
}
string Sportif::toString()
{
    return this->_nom + " " + this->_prenom + " " + to_string(this->_anneeNaissance);
}
int Sportif::getAge()
{
    return Outils::anneeActuelle() - this->_anneeNaissance;
}