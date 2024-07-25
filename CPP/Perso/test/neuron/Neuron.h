#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <cmath>
#include <cstdlib>

class Neuron {
public:
    double value;
    std::vector<double> weights;
    double bias;
    
    Neuron(int num_inputs);
    double activate(std::vector<double> inputs);

private:
    double sigmoid(double x);
};

#endif
