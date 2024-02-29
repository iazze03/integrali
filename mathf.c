/** \file mathf.c
    \brief Numeric integration of a polynomial
    \author Francesco Iazzetti

    First version of this software; all the functions are in this file  
*/

#include "mathf.h"

/*! \brief Computes the output value of a polynomial
    \param coeff coefficients of the polynomial (pointer to) 
    \param size length of the coeff array 
    \param in the input value 
    \return the output value
    
    The polynomial is structured as follows: coeff[0] + coeff[1]*x + ....
*/
float Polynomial(float* coeff, int size, float in) {
    
    int i;              // Counter for loops
    float out = 0.;     // Accumulator to compute the value of the function given an input
    float x = 1;        // To represent the different elements of the polynomial (x, x^2, x^3,...)  
    
    out = coeff[0];
    for (i = 1; i < size; i++) {
        out += coeff[i] * x;
        x *= in;            // x^i
    }
    
    return out;
}


/*! \brief Numerical integration according to the rectangular rule 
    \param values points that set the equally spaced intervals (pointer to) 
    \param size length of the values array 
    \param stepsize the interval between two points 
    \param integ1 integral computed using as reference the first point of each interval 
    \param integ2 integral computed using as reference the second point of each interval    
*/
void Rectangular(float* values, int size, float stepsize, float* integ1, float* integ2) {
    
    int i;  // Counter for loops

    (*integ1) = 0.;     // Initialize the first integral
    (*integ2) = 0.;     // Initialize the second integral
    
    (*integ1) += stepsize * values[0];
    for (i = 1; i < (size - 1); i++) {
        (*integ1) += stepsize * values[i];
        (*integ2) += stepsize * values[i];
    }
    (*integ2) += stepsize * values[i];
    
    return;
}


/*! \brief Numerical integration according to the trapezoidal rule 
    \param values points that set the equally spaced intervals (pointer to) 
    \param size length of the values array 
    \param stepsize the interval between two points 
    \return the computed integral  
*/
float Trapezoidal(float* values, int size, float stepsize) {
    
    int i;      // Counter for loops

    float integ = 0.;       // Accumulator to compute the integral
    float h = stepsize / 2.;  // To avoid dividing by 2 at each round of the loop
    
    for (i = 0; i < (size - 1); i++) 
        integ += h * (values[i + 1] + values[i]);
    
    return integ;
}
