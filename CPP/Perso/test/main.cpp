#include <iostream>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    wcout << L"Texte avec accents : é, à, ô" << endl;
    return 0;
}
