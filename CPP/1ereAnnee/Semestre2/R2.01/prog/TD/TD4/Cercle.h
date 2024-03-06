#ifndef CERCLE_H
#define CERCLE_H

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
#endif