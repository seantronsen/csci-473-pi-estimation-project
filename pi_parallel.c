#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


void validate(int argc, char **argv);

int main(int argc, char **argv) {

    // run validation
    validate(argc, argv);
    long num_iterations = atol(argv[1]);
    int num_threads = atoi(argv[2]);

    double start, stop;
    double approximation = 0.0;

    // calculate

    start = omp_get_wtime();
#pragma omp parallel for reduction(+:approximation) default(none) shared(num_iterations)  num_threads(num_threads)
    for (long k = 0; k < num_iterations; k++) {
        approximation += ((pow(-1, k)) / ((2 * k) + 1));
    }
    stop = omp_get_wtime();

    printf("Estimate for Pi: %.20lf\tElapsed Time: %5.10lf\n", (approximation * 4), (stop - start));
    exit(EXIT_SUCCESS);
}


void validate(int argc, char **argv) {
    if (argc != 3) {
        printf("%s <number_of_terms> <number_of_threads> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (!atol(argv[1])) {
        printf("%s <number_of_terms> <number_of_threads>\n", argv[0]);
        perror("A non-long-integer value was passed as an argument to <number_of_terms>...\n");
        exit(EXIT_FAILURE);
    }
    if (!atol(argv[2])) {
        printf("%s <number_of_terms> <number_of_threads>\n", argv[0]);
        perror("A non-integer value was passed as an argument to <number_of_threads>...\n");
        exit(EXIT_FAILURE);
    }

}