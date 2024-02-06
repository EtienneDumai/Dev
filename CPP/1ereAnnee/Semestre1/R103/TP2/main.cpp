/*
 Programme : convertirRGBEnGris.
 But : Afficher la valeur qu'il faudra mettre en html pour obteir du gris
 Date de dernière modification : 15/12/2023
 Auteur : Dumai Etienne
 Référence : R1.03 - feuille de TP n°2
*/
#include <iostream>
using namespace std;
#include "game-tools.h"
#include <math.h>
#include <cstring>
int conversion();
int red;
int blue;
int green;
int grisFctConversion;
bool couleurBonne = false;
string reponse;
int main(void)
{
    cout << conversion();
    cout << " est la valeur de votre gris a partie des valeur que vous avez convertie depuis " << reponse << endl;
    return 0;
}

int conversion()
{
    do
    {
        cout << "Quelle est le code RGB de votre rouge" << endl;
        cin >> red;
        effacer();
        if (red > 0 && red < 255)
        {
            couleurBonne = true;
        }
        else
        {
            cout << "le nombre doit etre compris entre 0 et 255" << endl;
            couleurBonne = false;
            pause(4);
            effacer();
        }

    } while (couleurBonne != true);
    do
    {
        cout << "Quelle est le code RGB de votre bleu" << endl;
        cin >> blue;
        effacer();
        if (blue > 0 && blue < 255)
        {
            couleurBonne = true;
        }
        else
        {
            cout << "le nombre doit etre compris entre 0 et 255" << endl;
            couleurBonne = false;
            pause(4);
            effacer();
        }

    } while (couleurBonne != true);
    do
    {
        cout << "Quelle est le code RGB de votre vert" << endl;
        cin >> green;
        effacer();
        if (green > 0 && green < 255)
        {
            couleurBonne = true;
        }
        else
        {
            cout << "le nombre doit être compris entre 0 et 255" << endl;
            couleurBonne = false;
            pause(4);
            effacer();
        }

    } while (couleurBonne != true);
    grisFctConversion = 0.2125 * red + 0.7154 * blue + 0.0721 * green;
    round(grisFctConversion);
    return grisFctConversion;
}



