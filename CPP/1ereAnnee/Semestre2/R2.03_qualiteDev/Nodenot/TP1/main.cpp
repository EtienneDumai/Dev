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
    catch (string s)
    {
        cout<<s<<endl;
    }
    return 0;
}
string Substring(const string chaine, int Deb, int Longueur)
{
    string chaineCoupe = "";
    if (Deb < 0)
    {
        throw string("Deb ne peut pas etre negatif");
    }
    if (Longueur < 0)
    {
        throw string("Longueur ne peut pas etre negatif");
    }
    if (Deb + Longueur > chaine.length())
    {
        throw string("Deb + Longueur ne peut pas etre superieur a la taille de la chaine");
    }


    for (int i = Deb; i <= Deb + Longueur; i++)
    {
        chaineCoupe += chaineCoupe + chaine[i];
    }

    return chaineCoupe;
}
