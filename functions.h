#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <complex.h>

#define pi 3.14159265359

double det(int k, double co[k][k]); // to calculate determinants

void slv_1stdegpoly(); // To solve linear equation
void slv_2nddegpoly(); // To solve quadratic equation(a*x^2 +b*x +c = 0)
void slv_3rddegpoly(); // To solve cubic equation(a*x^3 +b*x^2 +cx +d = 0)

void inputpoly(int k, float *coeff);
/*-It receives the coefficients from the user and stores it in an array
 -Its parameters are the degree of the polynomial and the coefficients array*/

void printpolsym(float coeff[], int k);
/*-To print the polynomial equation in a symbolic way
-Its parameters are the degree of the polynomial and the coefficients array*/

void solve_lineareqns(int k); // solving system of linear equations using Cramer's method

void inputsys(int k, double coeff[k][k + 1]);
/*-It receives the coefficients from the user and stores it in an array
-Its parameters are the order of the system and the coefficients array*/

void printsys(int k, double coeff[k][k + 1]);
/*-To print the system of linear equations in a symbolic way
  -Its parameters are the order of the system and the coefficients array*/

#endif // FUNCTIONS_H