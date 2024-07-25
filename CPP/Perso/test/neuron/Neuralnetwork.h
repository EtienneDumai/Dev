#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "Layer.h"

class NeuralNetwork {
public:
    std::vector<Layer> layers;

    NeuralNetwork(const std::vector<int>& topology);
    std::vector<double> predict(std::vector<double> inputs);
};

#endif
