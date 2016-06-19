//
// Created by devernua on 18.06.16.
//

#ifndef HOPFIELD_NETWORK_H
#define HOPFIELD_NETWORK_H
#include "Neuron.h"

typedef struct Network {
    Neuron *layer;
    size_t size;

} Network;

typedef struct Image {
    int *vector;
    size_t size;
} Image;

void learning(Network* N, Image * images, size_t img_num);

void start_execute(Network N, Image img);
int execute(Network N, Image img);

void scan_img(Image *img,size_t size);
void print_img(Image img, int lenstr);
void scan_network(Network * N, char *path, size_t size);
void print_network(Network N, char *path);


void destruct_network(Network* N);


#endif //HOPFIELD_NETWORK_H
