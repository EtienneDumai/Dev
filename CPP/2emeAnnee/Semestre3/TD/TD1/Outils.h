#ifndef OUTILS_H
#define OUTILS_H
#include <time.h>
class Outils {
    //Attributs non
    ///Méthodes
    public:
    //constructeur Non
    //destructeur Non
    //encapuslateur non 
    //methode usuelles non
    //methode specifique : anneeActuelle
    //Methode de classe qui retourne l'année actuelle
    static short int anneeActuelle(){
        time_t timer;
        struct tm *newTime;
        
        //demande l'heure que l'on récupère à l'adresse de timer 
        time (&timer);
        newTime = localtime(&timer);
        return (newTime->tm_year+1900);
    }
    protected: //non
    private: //non
};
#endif //OUTILS_H