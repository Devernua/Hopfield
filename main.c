#include <stdio.h>
#include <stdlib.h>
#include "Neuron.h"
#include "Network.h"

int main() {
   /* Neuron a;
    float w[] = {1, 2, 3.5, 5.5};
    int input[] = {-1, 1, 1, -1};
    init(&a, w, 4);
    printf("%d\n", a.size);
    printf("%f\n", summatory(a, input));
    printf("%d\n",activation(summatory(a, input)));
    destruct(&a);
    */
    Image images[2];
    size_t size = 25;
    scan_img(&images[0], size);
    scan_img(&images[1], size);
    Network net;
    learning(&net, images, 2);
    print_network(net, "/Users/devernua/proga/net.txt");

    Image ris;
    scan_img(&ris, size);

    int i = 0;
    while (execute(net, ris))
    {
        printf("%d\n", i);
        i++;
    }

    int k = 0;
    for ( i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d", (ris.vector[k] == 1)? 1 : 0);
            k++;
        }
        printf("\n");
    }



    return 0;
}