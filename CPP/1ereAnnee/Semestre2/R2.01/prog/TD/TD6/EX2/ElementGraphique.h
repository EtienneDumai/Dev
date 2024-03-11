#ifndef ELEMENTGRAPHIQUE_H
#define ELEMENTGRAPHIQUE_H

class ElementGraphique
{
private:
    int m_x, m_y;
    Couleur m_couleur;
public:
    //constructeur de copie:
    ElementGraphique(const ElementGraphique &autre);
    //constructeur permettant de preciser la position et la couleur
    ElementGraphique(int , int , Couleur);
    //methode qui permttar de placer l'élément grpahique à partir de 2 entiers
    void placer(int , int );
    //méthode qui rnvoie la coordonnée x de l'élément graphique
    int coordX() const;
    //méthode qui renvoie la coordonnée y de l'élément graphique
    int coordY() const;
    //methode qui permet de finir la cluleur de l'élément graphique
    void definirCouleur(Couleur);
    //methode qui renvoie la couleur de l'élément graphique
    Couleur couleur() const;
    
    virtual void afficher(Fenetre &f) const = 0;
    virtual void effacer(Fenetre &f) const = 0;
    virtual bool touche(int x, int y) const = 0;

};

#endif