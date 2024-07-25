#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "Neuron.h"

class Layer {
public:
    std::vector<Neuron> neurons;

    Layer(int num_neurons, int num_inputs_per_neuron);
    std::vector<double> feedForward(std::vector<double> inputs);
};

#endif
