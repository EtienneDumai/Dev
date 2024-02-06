/**
 * Fichier : main.cpp
 * But : Programme de prise en main de la notion de module
 *       v0 : le programme complet (sous-programme et main) implanté dans 1 seul fichier
 * Auteur : Pantxika Dagorret
 * date : 24-11-2023
 * Référence : feuille de TD n°3, exercice 0
 */
#include <iostream>
#include "MODULE_H.h"

int main(void)
{
    std::cout << "debut de main() " << std::endl;
    sp1();
    sp2();
    std::cout << "fin de main() " << std::endl;
    return 0;
}