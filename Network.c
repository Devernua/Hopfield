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
        init(&(N->layer[i]), size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < img_num; k++){
                N->layer[i].weight[j] += (images[k].vector[i] * images[k].vector[j]) / (float) size;
                N->layer[j].weight[i] = N->layer[i].weight[j];
            }
        }
    }
}

int execute(Network N, Image img)
{
    int value_changed = 0;
    int* old_vector = (int*) calloc(img.size, sizeof(int));
    for (int i = 0; i < img.size; i++)
        old_vector[i] = img.vector[i];
    Image old_image;
    old_image.vector = old_vector;
    old_image.size = img.size;

    for (int i = 0; i < N.size; i++)
    {
        img.vector[i] = activation(summatory(N.layer[i], old_image.vector));
        if (old_image.vector[i] != img.vector[i]) value_changed = 1;
    }

    return value_changed;
}

void scan_img(Image *img,size_t size)
{
    img->vector = (int *) calloc(size, sizeof(int));
    img->size = size;
    char buf;
    for (size_t i = 0; i < size; ){
        scanf("%c", &buf);
        if (buf == '0' || buf == '1')
        {
            img->vector[i] = (buf == '0')? -1 : 1;
            i++;
        }
    }

}

void print_img(Image img)
{
    for (int i = 0; i < img.size; i++)
        printf("%d", (img.vector[i] == 1)? 1 : 0);
}

void scan_network(Network * N, char *path, size_t size);
void print_network(Network N, char *path)
{
    FILE *f = fopen(path, "w");
    for (int i = 0; i < N.size; i++)
    {
        for (int j = 0; j < N.size; j++){
            fprintf(f, "%-6.2f ", N.layer[i].weight[j] );
        }
        fprintf(f,"\n");
    }
    fclose(f);
}


