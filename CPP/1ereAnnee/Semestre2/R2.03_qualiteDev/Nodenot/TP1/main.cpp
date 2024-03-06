#include <iostream>
#include <string>
using namespace std;

string Substring(const string chaine, int Deb, int Longueur);
string chaineTest;
int debut;
int longueur;
int main()
{
    cout << "Entrez la valeur de la chaine : ";
    cin >> chaineTest;
    cout << "Entrez la valeur de Deb sous la forme d'un entier :";
    cin >> debut;
    cout << "Entrez la valeur de Longueur sous la forme d'un entier :";
    cin >> longueur;
    try
    {
        Substring(chaineTest, debut, longueur);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
  string Substring(const string chaine, int Deb, int Longueur)
    {

        string chaineCoupe="";
        for (int i = Deb; i <= Deb+Longueur ; i++)
        {
            /* code */
        }
        
        try
        {
            if (Deb < 0)
            {
                throw string("Exception : Deb ne peut pas etre negatif");
            }
        }
        catch (string s)
        {
            cerr << s;
        }
        return string();
    }

    
