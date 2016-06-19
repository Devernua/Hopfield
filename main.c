#include <stdio.h>
//#include <stdlib.h>
#include "Neuron.h"
#include "Network.h"

int main() {
   /* Neuron a;
    float w[] = {1, 2, 3.5, 5.5};
    int input[] = {-1, 1, 1, -1};
    init_Neuron(&a, w, 4);
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

    Image test;
    Network new_net;
    scan_img(&test, size);
    scan_network(&new_net, "/Users/devernua/proga/net.txt", size);
    start_execute(new_net, test);
    print_img(test, 5);
    destruct_network(&net);
    destruct_network(&new_net);

    return 0;
}