#include <stdio.h>
#include <stdlib.h>
#include "gaussian_dist.h"
#include <getopt.h> /*(gérer les lignes de commande)*/

int main()
{
void print_usage() {
    printf("Usage: ./main -e expected_value -d std_deviation -n amount_of_values -o output_file -i input_file\n");
}

int main(int argc, char *argv[]) {
    int expected_value = 0;
    int std_deviation = 1;
    int amount_of_values = 100;
    char *output_file = NULL;
    char *input_file = NULL;
    int opt;

    while ((opt = getopt(argc, argv, "he:d:n:o:i:")) != -1) {
        switch (opt) {
            case 'h':
                print_usage();
                return 0;
            case 'e':
                expected_value = atoi(optarg);
                break;
            case 'd':
                std_deviation = atoi(optarg);
                break;
            case 'n':
                amount_of_values = atoi(optarg);
                break;
            case 'o':
                output_file = optarg;
                break;
            case 'i':
                input_file = optarg;
                break;
            default:
                print_usage();
                return 1;
        }
    }

    if (output_file == NULL && input_file == NULL) {
        print_usage();
        return 1;
    }

    if (output_file != NULL) {
        FILE *file = fopen(output_file, "w");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        print_gaussian_dist(expected_value, std_deviation, amount_of_values, file);
        fclose(file);
    }

    if (input_file != NULL) {
        FILE *file = fopen(input_file, "r");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        double mean, std_dev;
        calculate_gaussian_stats(file, &mean, &std_dev);
        fclose(file);

        printf("Mean: %f\n", mean);
        printf("Standard Deviation: %f\n", std_dev);
    }

    return 0;
}
}

