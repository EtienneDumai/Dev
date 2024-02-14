/**************************************************************************
 * PROGRAMME : Calcul moyenne pluviométrique d'un fichier de texte 
 *             dont le contenu peut être corrompu, cad contenant des 
 *             valeurs valeurs non numériques          
 *             Le module de gestion de fichiers : lève exception si fichier corrompu.            
 *             
 *             3 versions du sous-programme de calcul pluviométrique :
 *             - calculMoyenneSimple(nomSysPluvio) : Pas de schéma de récupération 
 *                                                   si fichier de données est corrompu.
 *             - calculMoyenneOuArretEcran(nomSysPluvio) : Schéma de récupération B. 
 *               Dès la première erreur constatée, le sous-programme la notifie à l'écran, dès
 *               puis s'arrête  en laissant le fichier dans un état stable (= fermé)
 *             - calculMoyenneOuArretLog(nomSysPluvio) : Schéma de récupération B. 
 *               Dès la première erreur constatée, le sous-programme la notifie dans un fichier 
 *               de texte (fichier Log), puis s'arrête  en laissant le fichier dans un état 
 *               stable (= fermé) 
 * 
 * VERSION DE BASE : --
 * AUTEUR : Dagorret
 * DATE : 02/02/2022
 * REMARQUES :
 *            Point de vigilance : affichage de l'exception !
***************************************************************************/

#include <iostream>
#include "stdlib.h"
#include "fichierTexte.h"
#include "sousProgrammes.h"

using namespace std;

int main()
{
    string nomSysPluvio ;     // nom système du fichier à lire
 
    //----------- TEST de calculMoyenneSimple avec 3 fichiers : 1 ok, 1 vide, 1 corrompu -----------------
    //----------------------------------------------------------------------------------------------------

    nomSysPluvio = "dec-2016";      // fichier ok
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "jan-2017";      // fichier vide
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "fev-2017";      // fichier corrompu
    cout << endl;
    calculMoyenneSimple(nomSysPluvio) ;
    cout << "...au revoir..." << endl;


    
    //----------- TEST de calculMoyenneOuArretEcran avec 3 fichiers : 1 ok, 1 vide, 1 corrompu -----------------
    //---------------------------------------------------------------------------------------------------- 
 
    /*
    nomSysPluvio = "dec-2016";      // fichier ok
    cout << endl;
    calculMoyenneOuArretEcran(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "jan-2017";      // fichier vide
    cout << endl;
    calculMoyenneOuArretEcran(nomSysPluvio) ;
    cout <<  "...au revoir..." << endl;

    nomSysPluvio = "fev-2017";      // fichier corrompu
    cout << endl;
    calculMoyenneOuArretEcran(nomSysPluvio) ;
    cout <<  "...au revoir..." << endl;

    */ 

    //----------- TEST de calculMoyenneOuArretLog avec 3 fichiers : 1 ok, 1 vide, 1 corrompu -----------------
    //----------------------------------------------------------------------------------------------------

    /*
    nomSysPluvio = "dec-2016";      // fichier ok
    calculMoyenneOuArretLog(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "jan-2017";      // fichier vide
    calculMoyenneOuArretLog(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    nomSysPluvio = "fev-2017";      // fichier corrompu
    calculMoyenneOuArretLog(nomSysPluvio) ;
    cout << "...au revoir..." << endl;

    */

    return 0;
}
