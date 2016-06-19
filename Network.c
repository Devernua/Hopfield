//
// Created by devernua on 19.06.16.
//

#include <stdio.h>
#include <stdlib.h>
#include "Neuron.h"
#include "Network.h"


void learning(Network* N, Image * images, size_t img_num)
{
    size_t size = images[0].size;

    N->size = size;
    N->layer = (Neuron *) calloc (size, sizeof(Neuron));

    for (int i = 0; i < size; i++)
        init_Neuron(&(N->layer[i]), size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < img_num; k++){
                N->layer[i].weight[j] += (images[k].vector[i] * images[k].vector[j]) / (float) size;
                N->layer[j].weight[i] = N->layer[i].weight[j];
            }
        }
    }
}

void start_execute(Network N, Image img)
{
    for (int i = 0; execute(N, img) && i < N.size; ++i);
}

int execute(Network N, Image img)
{
    int value_changed = 0;

    Image old_image;
    old_image.vector = (int*) calloc(img.size, sizeof(int));

    for (int i = 0; i < img.size; i++)
        old_image.vector[i] = img.vector[i];

    old_image.size = img.size;

    for (int i = 0; i < N.size; i++){
        img.vector[i] = activation(summatory(N.layer[i], old_image.vector));
        if (old_image.vector[i] != img.vector[i]) value_changed = 1;
    }
    free(old_image.vector);

    return value_changed;
}

void destruct_network(Network* N)
{
    for (int i = 0; i < N->size; ++i) {
        destruct(&(N->layer[i]));
    }
    free(N->layer);
}

void scan_img(Image *img,size_t size)
{
    img->vector = (int *) calloc(size, sizeof(int));
    img->size = size;

    char buf;

    for (size_t i = 0; i < size; ){
        scanf("%c", &buf);
        if (buf == '0' || buf == '1'){
            img->vector[i] = (buf == '0')? -1 : 1;
            i++;
        }
    }

}

void print_img(Image img, int lenstr)
{
    for (int i = 0; i < img.size; i++){
        if (i % lenstr == 0 && i){
            printf("\n");
        }
        printf("%d", (img.vector[i] == 1) ? 1 : 0);
    }
}

void scan_network(Network * N, char *path, size_t size)
{
    FILE *f = fopen(path, "r");

    N->size = size;
    N->layer = (Neuron *) calloc (size, sizeof(Neuron));

    for (int i = 0; i < size; i++)
        init_Neuron(&(N->layer[i]), size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            fscanf(f, "%f", &(N->layer[i].weight[j]));
        }
    }
    fclose(f);
}

void print_network(Network N, char *path)
{
    FILE *f = fopen(path, "w");
    for (int i = 0; i < N.size; i++){
        for (int j = 0; j < N.size; j++){
            fprintf(f, "%-6.2f ", N.layer[i].weight[j] );
        }
        fprintf(f,"\n");
    }
    fclose(f);
}


