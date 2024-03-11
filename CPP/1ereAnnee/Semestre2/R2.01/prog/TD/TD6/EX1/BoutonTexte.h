#ifndef BOUTONTEXTE_H
#define BOUTONTEXTE_H
#include "Bouton.h"

class BoutonTexte : public Bouton
{
    private:
        char* m_texte;
    public:
        BoutonTexte();
        BoutonTexte(const BoutonTexte &autre);
        BoutonTexte(const Bouton &b, char* texte="sans texte");
        ~BoutonTexte();
        //méthode permettant de définir le texte du bouton
        void definirTexte(const char* texte);
        //méthode pour afficher le bouton et son texte
        void afficher(Fenetre &f) const;
        //méthode pour effacer le bouton et son texte
        void effacer(Fenetre &f) const;


};
#endif