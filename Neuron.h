//
// Created by devernua on 18.06.16.
//

#ifndef HOPFIELD_NEURON_H
#define HOPFIELD_NEURON_H

#include <ntsid.h>

typedef struct Neuron{
    float* weight;
    size_t size;
} Neuron;

void init_Neuron(Neuron *a, size_t size);
void destruct(Neuron *a);
float summatory(Neuron a, int* input);
int activation(float sum);




#endif //HOPFIELD_NEURON_H
