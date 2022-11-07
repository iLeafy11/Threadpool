void *leibniz(void *args)
{
    int i = *(int *) args;
    double tmp = (i & 1) ? (-1) : 1;
    double *product = malloc(sizeof(double));
    if (product)
        *product = 4.0 * tmp / (2 * i + 1);
    return (void *) product;
}

double compute_pi_leibniz(size_t N)
{
    double pi = 0.0;
    for (size_t i = 0; i < N; i++) {
        double tmp = (i & 1) ? (-1) : 1;
        pi += tmp / (2 * i + 1);
    }
    return 4.0 * pi;
}
