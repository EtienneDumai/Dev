#include <iostream>
#include "game-tools.h"
#include <locale>
using namespace std;

wstring messageACrypter;

void demanderMessage(wstring &message);
void encrypterLeMessage(wstring& message);
int main()
{
    setlocale(LC_ALL, "");
    demanderMessage(messageACrypter);
    encrypterLeMessage(messageACrypter);
    return 0;
}

void demanderMessage(wstring &message)
{
    wcout << "Quel est le message que vous voulez encrypter via le systeme de la roue de Cesar"<<endl;
    wcin >> message;
}

void encrypterLeMessage(wstring &message)
{
    setlocale(LC_ALL, "");
    int memTemp;
    wstring memTempString;
    wstring messageCode;
    int nbrDeCryptage;
    nbrDeCryptage = random(1,26);
    for (int i = 0; message[i] != '\0'; i++)
    {
        memTemp = int(message[i])+nbrDeCryptage;
        memTempString=wchar_t(memTemp);
        messageCode+= memTempString;
    }
    wcout<<"Voici le message encrypte"<<endl;
    wcout<<messageCode;
}
