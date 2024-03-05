#include "Bouton.h"

Bouton::Bouton(const Bouton &autre) {

}

Bouton::Bouton() {

}

Bouton::Bouton(const Cercle &c, bool etat) {

}

void Bouton::definir(int x, int y, int r, int rouge, int vert, int bleu, bool etat) {
    
}

void Bouton::definir(int x, int y, int r, const Couleur &couleur, bool etat) {

}

void Bouton::activer(bool etat) {

}

void Bouton::desactiver(bool etat) {

}

bool Bouton::actif() const {

}

int Bouton::coordX() const {

}

int Bouton::coordY() const {

}

int Bouton::rayon() const {

}

Couleur Bouton::couleur() const {

}

void Bouton::definirCouleur(Couleur couleur) {

}

void Bouton::afficher(Fenetre &f) const {

}

void Bouton::effacer(Fenetre &f) const {
    
}

bool Bouton::touche(int x, int y) const {
    
}
