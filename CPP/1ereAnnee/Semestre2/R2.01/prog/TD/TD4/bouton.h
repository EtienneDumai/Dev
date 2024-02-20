#ifndef BOUTON_H
#define BOUTON_H
class Bouton
{
private:
    void dessinerEtat(Fenetre &, Couleur)const;
    Cercle m_cercle;
    bool m_estActif;

public:
    // procédure pour definir la position, la taille, sa couleur(trois entiers entre 0 et 255) et eventuellement son etat
    void definir(int, int, int , int , int , int , bool  = false);
    // procédure pour definir la position, la taille,eventuellement sa couleur(un objet de calsse Couleur) et eventuellement son etat, par défaut le bouton sera bleu et inactif
    void definir(int , int , int , Couleur  = Couleur(0, 0, 255), bool  = false);
    // procédure qui permet de definir l'etat du bouton à activé
    void activer(bool  = true);
    // procdure qui met le bouton dans un etat inactif
    void desactiver(bool  = false);
    // fonction qui retourne true si le bouton est activé, false sinon
    bool actif() const;
    // fonction qui retourne la coordonnée x du bouton
    int coordX() const;
    // fonction qui retourne la coordonnée y du bouton
    int coordY() const;
    // fonction qui retourne le rayon du bouton
    int rayon() const;
    // fonction couleur qui retourne la couleur du bouton
    Couleur couleur() const;
    // procédure qui définie la couleur du bouton a partir de la classe Couleur
    void definirCouleur(Couleur );
    // procédure qui permet d'afficher le bouton dans la fenetre passé en paramètre
    void afficher(Fenetre &) const;
    // procédure qui permet d'effacer le bouton de la fenetre passé en paramètre
    void effacer(Fenetre &) const;
    // fonction touche qui retourne true si les coordonnées passées en paramètres sont celles d'un point situé à l'intérieur du bouton, false sinon
    bool touche(int , int ) const;
};

#endif
