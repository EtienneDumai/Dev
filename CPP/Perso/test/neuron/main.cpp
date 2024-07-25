#include <iostream>
#include <vector>
#include <ctime>
#include "NeuralNetwork.h"

int main() {
    // Initialiser le générateur de nombres aléatoires avec le temps courant
    srand(static_cast<unsigned int>(time(0)));

    std::vector<int> topology = {2, 3, 1}; // 2 neurones d'entrée, 1 couche cachée avec 3 neurones, 1 neurone de sortie
    NeuralNetwork nn(topology);

    std::vector<double> inputs = {0.5, 0.1};
    std::vector<double> outputs = nn.predict(inputs);

    for (double output : outputs) {
        std::cout << output << std::endl;
    }

    return 0;
}
