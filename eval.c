#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "leibniz.h"

static void *bbp(void *arg)
{
    int k = *(int *) arg;
    double sum = (4.0 / (8 * k + 1)) - (2.0 / (8 * k + 4)) -
                 (1.0 / (8 * k + 5)) - (1.0 / (8 * k + 6));
    double *product = malloc(sizeof(double));
    if (product)
        *product = 1 / pow(16, k) * sum;
    return (void *) product;
}

int main(int argc, char *argv[])
{
    int size = 10;
    double p1 = compute_pi_leibniz(size);
    double p2 = 0;
    for (int i = 0; i < size; i++) {
        p2 += *(double *) bbp(&i);
    }
    printf("%.15f %.15f\n", p1, p2);
    return 0;
}
