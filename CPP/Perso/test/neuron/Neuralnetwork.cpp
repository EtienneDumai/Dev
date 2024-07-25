#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(const std::vector<int>& topology) {
    for (int i = 0; i < topology.size() - 1; ++i) {
        layers.push_back(Layer(topology[i + 1], topology[i]));
    }
}

std::vector<double> NeuralNetwork::predict(std::vector<double> inputs) {
    for (auto& layer : layers) {
        inputs = layer.feedForward(inputs);
    }
    return inputs;
}
