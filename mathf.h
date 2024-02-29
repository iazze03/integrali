/** \file mathf.h
    \brief Numeric integration of a polynomial
    \author Francesco Iazzetti

    First version of this software; all the functions are in this file  
*/
#ifndef MATHF_H
#define MATHF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float Polynomial(float* coeff, int size, float in);
void Rectangular(float* values, int size, float stepsize, float* integ1, float* integ2);
float Trapezoidal(float* values, int size, float stepsize);

#endif
