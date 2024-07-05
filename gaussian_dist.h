#ifndef GAUSSIAN_DIST_H
#define  GAUSSIAN_DIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



void print_gaussian_dist ( int expected_value, int std_deviation , int amount_of_values, FILE * output_stream){

srand(time(NULL));
for(int i=0;i < amount_of_values;i++){

    //Erstellung von  zufaelligen und uniformen Zaehler zws 0 und 1
    double u1=((double)rand()/RAND_MAX);
    double u2=((double)rand()/RAND_MAX);

   //Box-Muller Method
   double z0 = sqrt( - 2.0 log(u1)) * cos(2.0 * pi * u2);

   //Adjustment average and ecart-type
   double value =  expected_value + z0 * std_deviation

   fprintf(output_stream,"%f\n",value);

}


}

#endif
