#ifndef GAUSSIAN_DIST_H
#define  GAUSSIAN_DIST_H

#include <stdio.h>

void print_gaussian_dist ( int expected_value, int std_deviation , int amount_of_values, FILE * output_stream);
void calculate_gaussian_stats(FILE *input_stream, double *mean, double *std_dev);

#endif
