#include <iostream>
using namespace std;
class Sportif
{
private:
    string _prenom;
    string _nom;
    int _anneeNaissance;

public:
    Sportif(string, string, int);
    virtual ~Sportif();
    string getPrenom();
    string getNom();
    int getAnneeNaissance();
};
