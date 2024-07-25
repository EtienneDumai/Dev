#include "Layer.h"

Layer::Layer(int num_neurons, int num_inputs_per_neuron) {
    for (int i = 0; i < num_neurons; ++i) {
        neurons.push_back(Neuron(num_inputs_per_neuron));
    }
}

std::vector<double> Layer::feedForward(std::vector<double> inputs) {
    std::vector<double> outputs;
    for (auto& neuron : neurons) {
        outputs.push_back(neuron.activate(inputs));
    }
    return outputs;
}
