#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include "Neuron.h"
#include "Network.h"

int main(int argc, char* argv[]) {
    if ((argc == 4) && !(strcmp(argv[1], "-l"))){
        size_t m = (size_t) atoi(argv[2]);
        Image images[m];
        int h = (int) (floor(sqrt(m / 0.14)) + 1);
        size_t size = (size_t) h * h;
        printf("Введите %d образов размера %dx%d\n", (int) m, h, h);
        for (int i = 0; (i < m); ++i) {
            scan_img(&images[i], size);
        }
        Network net;
        learning(&net, images, m);
        print_network(net, argv[3]);
        destruct_network(&net);
    }
    else if ((argc == 4) && !(strcmp(argv[1], "-e"))){
        int h = atoi(argv[2]);
        size_t size = (size_t) h * h;
        Network net;
        scan_network(&net, argv[3], size);
        printf("Введите образ, который хотите распознать размера %dx%d\n", h, h);
        Image test;
        scan_img(&test, size);
        start_execute(net, test);
        print_img(test, h);
        destruct_network(&net);
    }
    else if (argc != 4) {
        printf("Неверное число или тип введенных параметров\n");
        printf("Пример ввода:\n");
        printf("-l 3 User/devernua/proga/net.txt\n-e 5 User/devernua/proga/net.txt\n");
        printf("-l - режим обучения, m - число образов, path - путь до файла для сохранения параметров сети\n");
        printf("-e - режим опознавания,  size - размер стороны матрицы образа, path - путь до файла используемых параметров сети");
        return 1;
    }

   /* Neuron a; //тест структуры нейрон
    float w[] = {1, 2, 3.5, 5.5};
    int input[] = {-1, 1, 1, -1};
    init_Neuron(&a, w, 4);
    printf("%d\n", a.size);
    printf("%f\n", summatory(a, input));
    printf("%d\n",activation(summatory(a, input)));
    destruct(&a);
    */

    /*Image images[2]; //тест всей сети
    size_t size = 25;
    scan_img(&images[0], size); //два образа в виде массива 5 на 5
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
    destruct_network(&new_net);*/

    return 0;
}