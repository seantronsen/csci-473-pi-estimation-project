#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


void validate(int argc, char **argv);

int main(int argc, char **argv) {

    // run validation
    validate(argc, argv);
    long num_iterations = atol(argv[1]);

    double start, stop;
    double approximation = 0.0;
    start = omp_get_wtime();
    for (long k = 0; k < num_iterations; k++) {
        approximation += ((pow(-1, k)) / ((2 * k) + 1));
    }

    stop = omp_get_wtime();
    printf("Estimate for Pi: %.20lf\tElapsed Time: %5.10lf\n", (approximation * 4), (stop - start));
    exit(EXIT_SUCCESS);
}


void validate(int argc, char **argv) {
    if (argc != 2) {
        printf("%s <number_of_terms>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (!atol(argv[1])) {
        printf("%s <number_of_terms>\n", argv[0]);
        perror("A non-long-integer value was passed as an argument to the program...\n");
        exit(EXIT_FAILURE);
    }
}


