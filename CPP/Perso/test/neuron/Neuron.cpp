#include "Neuron.h"

Neuron::Neuron(int num_inputs) {
    bias = ((double) rand() / (RAND_MAX));
    for (int i = 0; i < num_inputs; ++i) {
        weights.push_back(((double) rand() / (RAND_MAX)));
    }
}

double Neuron::activate(std::vector<double> inputs) {
    double sum = bias;
    for (int i = 0; i < inputs.size(); ++i) {
        sum += weights[i] * inputs[i];
    }
    return sigmoid(sum);
}

double Neuron::sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}
