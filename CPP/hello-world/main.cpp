#include <iostream>
#include <string>

void epelerMot(const std::string& mot) {
    for (size_t i = 0; i < mot.length(); ++i) {
        std::cout << mot[i] << std::endl;
    }
}

int main() {
    std::string mot = "Hello";
    epelerMot(mot);
    return 0;
}
