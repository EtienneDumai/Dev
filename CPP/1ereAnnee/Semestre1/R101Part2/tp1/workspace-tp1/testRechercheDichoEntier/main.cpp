/*
 Programme : testRechercheDichoDecEntier.
 But :  Tester la conformité du sous-programme recherchePremiereOccDec
        effectuant une recherche dichotomique dans un tableau d'entiers trié par ordre décroissant
 Date de dernière modification : 10/11/2023
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°1
*/

#include <iostream>

using namespace std;

/* Les sous-programmes servant à faire les tests
----------------------------------------------- */
void testRechercheDichoDecEntier(); // test de recherchePremiereOccDec() sur un tableau d'entiers

void afficher(const int tab[],
              unsigned short int lgTab);
/* But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments
         si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide') */

/* Les sous-programmes testés
----------------------------- */
void recherchePremiereOccDec(const int tab[],
                             unsigned int lgTab,
                             int val,
                             unsigned int &pos,
                             bool &trouve);
/* But : étant donnés val, une variable entière et le tableau tab, de lgTab cases,
       ordonné par ordre décroissant de valeurs, éventuellement avec doublons,
       recherche la première occurrence de val, selon un parcours dichotomique du tableau.
       Si elle est trouvée, trouve = vrai et pos = l'indice où elle a été trouvée
       Sinon, trouve = faux
   pré-condition : tab est ordonné par ordre décroissant de valeurs */

/* MAIN
---------------------------*/
int main()
{
    testRechercheDichoDecEntier();
    return 0;
}
/*---------------------------*/

/* Corps des sous-programmes servant à faire les tests
------------------------------------------------------ */
void testRechercheDichoDecEntier()
{
    const unsigned int TAILLE = 10;
    int tableau[TAILLE] = {60, 45, 45, 45, 45, 10, 0, -15, -20, -45};

    int valCherchee;       // entier cherché dans tableau
    unsigned int position; // 1ere position trouvee de la valeur cherchee, si elle est trouvée dans tab
    bool valTrouvee;       // indicateur de reussite / échec de la recherche

    afficher(tableau, TAILLE);

    // Tester : tableau, 0
    valCherchee = 0;
    /**A COMPLETER-1 **/ // appel du sous-programmed e recherche
    recherchePremiereOccDec(tableau,
                            TAILLE,
                            valCherchee,
                            position,
                            valTrouvee);
        // valTrouvee, [position], valCherchee >> exploiter résultat >> (écran)
        if (valTrouvee)
    {
        cout << valCherchee << " trouvee ? "
             << "VRAI, " << position << endl;
    }
    else
    {
        cout << valCherchee << " trouvee ? "
             << "FAUX,  -- " << endl;
    }
}

void afficher(const int tab[],
              unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i < lgTab - 1; i++)
        {
            cout << tab[i] << ", ";
        };
        cout << tab[lgTab - 1] << "} " << endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

/*---------------------------*/

/* Corps des sous-programmes à tester
-------------------------------------*/

void recherchePremiereOccDec(const int tab[],
                             unsigned int lgTab,
                             int val,
                             unsigned int &pos,
                             bool &trouve)
{
    int bInf = 0;         // borne inferieure de l'espace de recherche, calculee
    int bSup = lgTab - 1; // borne inferieure de l'espace de recherche, calculee
    unsigned int milieu;  // indice du milieu de l'espace de recherche.
    // définit l'élement courant de tab à évaluer et comparer à val

    /**A COMPLETER-2 **/ // corps du sous-programme de recherche
    trouve = false;

    while (!(bInf>bSup))
    {
        milieu = (bInf + bSup) / 2;
        if (tab[milieu] == val)
        {
            trouve = true;
            pos = milieu;
            break;
        }
        if (val < tab[milieu])
        {
            bInf = milieu + 1;
        }
        else
        {
            bSup = milieu - 1;
        }
    }
}