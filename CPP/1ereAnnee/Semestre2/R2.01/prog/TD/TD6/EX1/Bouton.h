#ifndef BOUTON_H
#define BOUTON_H

#include <iostream>
using namespace std;

struct Couleur
{
    string m_couleur;
};

class Cercle
{
private:
    Cercle int m_x, m_y;
    int m_rayon;
    Couleur m_couleur;

public:
    Cercle(int x = 20, int y = 20, int r = 10, const Couleur &couleur = Couleur(0, 0, 255)); // Constructeur par défaut
    Cercle(int x, int y, int r, const Couleur &couleur = Couleur(0, 0, 255));                // Constructeur avec paramètres
    Cercle(const Cercle &autre);                                                             // Constructeur de copie
    void placer(int x, int y);
    void dimensionner(int rayon);
    void definirCouleur(int r, int v, int b);
    void definirCouleur(Couleur uneCouleur);
    int coordX() const;
    int coordY() const;
    int rayon() const;
    Couleur couleur() const;
    void afficher(Fenetre &f) const;
    void effacer(Fenetre &f) const;
    bool touche(int x, int y) const;
};

class Bouton : public Cercle
{
private:
    bool m_estActif;
    void dessinerEtat(Fenetre &f, Couleur) const;

public:
    // constructeur de copie d'un bouton
    Bouton(const Bouton &autre);
    // constructeur par défaut qui créer un bouton dont le cercle est celui par defaut et qui est inactif
    Bouton();
    // constructeur permettant de créer un bouton à partir d'un cercle et d'un etat
    Bouton(const Cercle &c, bool etat = false);

    /* methode pour definir sa position, sa taille (rayon du cercle), sa couleur ( trois entiers) et
    eventuellement son état. Par défaut le bouton sera inactif*/
    void definir(int x, int y, int rayon, int rouge, int vert, int bleu, bool etat = false);
    /*methode pour definir sa position, sa taille (rayon du cercle), sa couleur (objet de la classe Couleur)
    puis son etat. Par défaut le bouton sera bleu et inactif*/
    void definir(int x, int y, int rayon, const Couleur &couleur = Couleur(0, 0, 255), bool etat = false);
    // methode activer qui met le dans l'etat actif
    void activer(bool etat = true);
    // methode desactiver qui met le bouton dans l'etat inactif
    void desactiver(bool etat = false);
    // methode actif qui retourne true si le bouton est actif, false sinon
    bool actif() const;
    // methode qui retourne la coordonnée x du bouton
    int coordX() const;
    // methode qui retourne la coordonnée y du bouton
    int coordY() const;
    // methode qui retourne le rayon du bouton
    int rayon() const;
    // methode couleur qui retourne la couleur du bouton
    Couleur couleur() const;
    // methode definirCouleur qui permet de definir la couleur du bouton à partir de la classe Couleur
    void definirCouleur(Couleur couleur);
    // methode afficher qui permet d'afficher le bouton dans la fenetre passée en paramètre
    void afficher(Fenetre &f) const;
    // methode effacer qui permet d'effacer le bouton de la fenetre passée en paramètre
    void effacer(Fenetre &f) const;
    // methode touche qui retourne true si les coordonnées passées en paramètres sont celles d'un point situé à l'intérieur du bouton, false sinon
    bool touche(int x, int y) const;
};

#endif
