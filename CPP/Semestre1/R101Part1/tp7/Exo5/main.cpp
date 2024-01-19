/*
 Programme : Compter les valeurs négatives d'un tableau
 But :  Compter les valeurs négatives d'un tableau
 Date de dernière modification : 19 octobre 2023
 Auteur : E. Dumai
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main(void)
{
    // VARIABLES
    struct Etudiant
    {
        string nom;            // nom de l'étudiant
        string prenom;         // prénom de l'étudiant
        unsigned short int td; // numéro de TD de l'étudiant
        unsigned short int tp; // numéro de TP de l'étudiant
    };
    // nombres d'étudiants inscrits en semestre 1
    const unsigned int EFFECTIF_S1 = 70;
    // nombres d'étudiants inscrits en semestre 3
    const unsigned int EFFECTIF_S3 = 60;

    // Etudiants inscrits en semestre 1
    Etudiant etudiantsS1[EFFECTIF_S1];
    // Etudiants inscrits en semestre 3
    Etudiant etudiantsS3[EFFECTIF_S3];

    Etudiant promo[100];              // Tableau contenant les étudiants d'un semestre donné
    unsigned short int effectifPromo; // Le nombre d'étudiants enregistré dans la promo
    unsigned short int numTp;         // Le numéro de groupe de TP dont il faut détérminer l'effectif

    // TRAITEMENTS
    cout << "saisissez le numéro de TP :" << endl;
    cin >> numTp;
    int effectifTp = 0;
    for (int indiceCaseCourante = 0; indiceCaseCourante < (effectifPromo - 1); indiceCaseCourante++)
    {
        if (promo[indiceCaseCourante].tp == numTp)

        {
            effectifTp += 1;
        }
    }
    cout << effectifTp;
}
