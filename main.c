/** \file main.c
    \brief Numeric integration of a polynomial
    \author Francesco Iazzetti

    First version of this software; all the functions are in this file  
*/


#include <stdio.h> 
#include <stdlib.h> 
#include "mathf.h"

int main() {

    /* Setting all the parameters */
    float fcoeff[4] = {-10.0, 1.0, 0.0, 2.0};   // The polynomial coefficients
    float xmin = 0.0;                           // The integration range start
    float xmax = 5.0;                           // The integration range end
    int intervals = 1000;                       // Number of equally spaced intervals
    
    float integ1, integ2;
    
    int i; 
    float in = xmin;
    float gap = (xmax - xmin) / (float)intervals;
    float* fvalues = NULL;
    
    /* This array will store the (intervals + 1) values of the polynomial that delimit the equally spaced intervals */
    fvalues = (float*)malloc(sizeof(float) * (intervals + 1));
    if (fvalues == NULL) {
        printf("\nERROR: cannot allocate memory\n");
        exit(-1);
    } /* This verification should be done when allocating an array to check if it has been allocated correctly. */

    /* To get the value of the polynomial at the different points that are delimiting the intervals */
    for (i = 0; i <= intervals; i++) {
        fvalues[i] = Polynomial(fcoeff, 4, in);
        in += gap;
    }
    
    integ1 = 0.; 
    integ2 = 0.;

    /* To compute the integral according to the rectangular rule */
    Rectangular(fvalues, intervals + 1, gap, &integ1, &integ2);
    printf("\nRectangular rule - The integral between %f and %f is in the interval: [%f,%f]\n", xmin, xmax, integ1, integ2);
    
    /* To compute the integral according to the trapezoidal rule */
    integ1 = Trapezoidal(fvalues, intervals + 1, gap);
    printf("\nTrapezoidal rule - The integral between %f and %f is : %f\n", xmin, xmax, integ1);
    
    /* Deallocation */
    if (fvalues != NULL)
        free(fvalues);

    return 0;
}
