/** \file main.c
	\brief Numeric integration of a polynomial
	\author Francesco Iazzetti

	first version of this software; all the functions are in this file  
*/


#include <stdio.h> 
#include <stdlib.h> 
#include "mathf.h"




/*! \brief computes the output value of a polynomial
	\param coeff coefficients of the polynomial (pointer to) 
	\param size length of the coeff array 
	\param in the input value 
	\return the output value
	
	the polynomial is structured as follows: coeff[0] + coeff[1]*x + .... */

int main() {

	/* setting all the parameters */
	float fcoeff[4] = {-10.0,1.0,0.0,2.0};	/* the polynomial */
	float xmin = 0.0; 						/* the integration range */ 
	float xmax= 5.0; 					
	int intervals = 1000; 					/* number of equally spaced intervals */ 
	
	
	float integ1, integ2;
	
	int i; 
	float in = xmin;
	float gap = (xmax-xmin)/(float)intervals;
	float* fvalues = NULL;
	
	/* this array will store the (steps+1) values of the polynomial that are delimiting the equally spaced intervals*/
	fvalues = (float*)malloc(sizeof(float)*(intervals+1));
	if (fvalues == NULL) {
		printf("\nERROR: cannot allocate memory\n");
		exit(-1);
	} /* questa verifica va fatta quando alloco un array per verificare se è stato allocato correttamente.*/

	/* to get the value of the polynomial at the different points that are delimiting the intervals */
	for (i=0; i<=intervals; i++) {
		fvalues[i] = Polynomial(fcoeff,4,in);
		in += gap;
	}
	
	integ1= 0.; 
	integ2= 0.;

	/* to compute the integral according to the rectangular rule */
	Rectangular(fvalues,intervals+1,gap,&integ1,&integ2);
	printf("\nRectangular rule - The integral between %f and %f is in the interval: [%f,%f]\n", xmin,xmax,integ1,integ2);
	
	/* to compute the integral according to the trapezoidal rule */
	integ1 = Trapezoidal(fvalues,intervals+1,gap);
	printf("\nTrapezoidal rule - The integral between %f and %f is : %f\n", xmin,xmax,integ1);
	
	/* deallocation */
	if (fvalues != NULL)
		free(fvalues);

	return 0;
}