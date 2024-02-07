#include <iostream>
#include "game-tools.h"
using namespace std;

string messageACrypter;

void demanderMessage(string &message);
void encrypterLeMessage(string& message);
int main()
{
    demanderMessage(messageACrypter);
    encrypterLeMessage(messageACrypter);
    return 0;
}

void demanderMessage(string &message)
{
    cout << "Quel est lemessage que vous voulez encrypter via le systeme de la roue de Cesar";
    cin >> message;
}

void encrypterLeMessage(string &message)
{
    int memTemp;
    string memTempString;
    string messageCode;
    int nbrDeCryptage;
    nbrDeCryptage = random(1,26);
    for (int i = 0; message[i] != '\0'; i++)
    {
        memTemp = int(i)+nbrDeCryptage;
        memTempString=char(memTemp);
        messageCode+= memTempString;
    }
    cout<<"Voici le message encrypte"<<messageCode<<endl;
}
