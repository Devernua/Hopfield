//
// Created by devernua on 18.06.16.
//

#include "Neuron.h"
#include <stdio.h>
#include <stdlib.h>

void init_Neuron(Neuron *a, size_t size)
{
    a->size = size;
    a->weight = (float *) calloc(size, sizeof(float));
    for (size_t i = 0; i < size; i++)
        a->weight[i] = 0;
}

void destruct(Neuron *a)
{
    free(a->weight);
    a->weight = NULL;
    a->size = 0;
}

float summatory(Neuron a, int* input)
{
    float sum = 0;
    for (size_t i = 0; i < a.size; i++){
        sum += a.weight[i] * input[i];
    }
    return sum;
}

int activation(float sum)
{
    return (sum >= 0) ? 1 : -1;
}