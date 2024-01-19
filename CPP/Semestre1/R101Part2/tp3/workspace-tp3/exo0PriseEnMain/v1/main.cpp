/**
 * Fichier : main.cpp
 * But : Programme de prise en main de la notion de module
 *       v0 : le programme complet (sous-programme et main) implanté dans 1 seul fichier
 * Auteur : Pantxika Dagorret
 * date : 24-11-2023
 * Référence : feuille de TD n°3, exercice 0
 */
#ifndef MODULE_H
#define MODULE_H
#include <iostream>

void sp1();
void sp2();

int main(void)
{
    std::cout << "debut de main() " << std::endl;
    sp1();
    sp2();
    std::cout << "fin de main() " << std::endl;
    return 0;
}

void sp1()
{
    std::cout << "sous-programme 1" << std::endl;
}

void sp2()
{
    std::cout << "sous-programme 2" << std::endl;
}
#endif