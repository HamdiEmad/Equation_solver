#include <complex.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159
float det_2(float co[2][2]); // To calculate 2x2 determinant
float det_3(float co[3][3]); // To calculate 3x3 determinant
float det_4(float co[4][4]); // To calculate 4x4 determinant

void slv_1stdegpoly(); // To solve linear equation
void slv_2nddegpoly(); // To solve quadratic equation(a*x^2 +b*x +c = 0)
void slv_3rddegpoly(); // To solve cubic equation(a*x^3 +b*x^2 +cx +d = 0)

void inputpoly(const unsigned short k, float *coeff);
/*-It receives the coefficients from the user and stores it in an array
 -Its parameters are the degree of the polynomial and the coefficients array*/

void printpolsym(float coeff[], const unsigned short k);
/*-To print the polynomial equation in a symbolic way
-Its parameters are the degree of the polynomial and the coefficients array*/

void slv_2lineareqns();
// To solve a system of 2 linear equations(an*X1 +bn*X2 = cn) Using Cramer's method
void slv_3lineareqns();
// To solve a system of 3 linear equations(an*X1 +bn*X2 +cn*X3 = dn) Using Cramer's method
void slv_4lineareqns();
// To solve a system of 4 linear equations(an*X1 +bn*X2 +cn*X3 +dn*X4 = en) Using Cramer's method

void inputsys(const unsigned short k, float coeff[k][k + 1]);
/*-It receives the coefficients from the user and stores it in an array
-Its parameters are the order of the system and the coefficients array*/

void printsys(const unsigned short k, float coeff[k][k + 1]);
/*-To print the system of linear equations in a symbolic way
  -Its parameters are the order of the system and the coefficients array*/

int main(void)
{
    while (1) // To repeat the program until a terminating statement
    {
        printf("Please choose the type of problem:\n");
        printf("1- Linear equation(a*X +b = 0)\n");
        printf("2- Quadratic equation(a*x^2 +b*x +c = 0)\n");
        printf("3- Cubic equation(a*x^3 +b*x^2 +cx +d = 0)\n");
        printf("4- System of 2 linear equations(an*X1 +bn*X2 = cn)\n");
        printf("5- System of 3 linear equations(an*X1 +bn*X2 +cn*ْX3 = dn)\n");
        printf("6- System of 4 linear equations(an*X1 +bn*X2 +cn*ْX3 +dn*X4 = en)\n");
        printf("Press the corresponding number to choose the problem type\n\n");
        char c = 0, t = 0;
        t = getch();
        switch (t)
        {
            case ('1'):
                slv_1stdegpoly();
                break;
            case ('2'):
                slv_2nddegpoly();
                break;
            case ('3'):
                slv_3rddegpoly();
                break;
            case ('4'):
                slv_2lineareqns();
                break;
            case ('5'):
                slv_3lineareqns();
                break;
            case ('6'):
                slv_4lineareqns();
                break;
        }
        printf("Press any key to exit, Y to continue\n\n ");
        // Asks the user whether to continue or exit
        c = getch();
        if (c == 'Y' || c == 'y')
            continue;
        else
            return 0;
    }
}

void slv_1stdegpoly() // To solve linear equation(a*X +b = 0)
{
    float coeff[2] = {0};
    printf("Enter the coefficients of the equation(a*X +b = 0): \n");
    inputpoly(1, &coeff[0]);

    if (coeff[0] == 0)
        printf("Math ERROR\n");
    else
    {
        printpolsym(coeff, 1);
        printf("X = %.3f\n", coeff[1] == 0 ? 0 : (-coeff[1] / coeff[0]));
    }
}
void slv_2nddegpoly() // To solve quadratic equation(a*x^2 +b*x +c = 0)
{
    float coeff[3] = {0}, dis = 0;
    printf("Enter the coefficients of the equation(a*x^2 +b*X +c = 0): \n");
    inputpoly(2, coeff);

    dis = coeff[1] * coeff[1] - 4 * coeff[0] * coeff[2];
    if (coeff[0] == 0)
        printf("Math ERROR\n");
    else
    {
        printpolsym(coeff, 2);
        if (dis >= 0)
        {
            printf("X1 = %.3f\t", ((-coeff[1] - sqrt(dis)) / (2 * coeff[0])));
            printf("X2 = %.3f \n", ((-coeff[1] + sqrt(dis)) / (2 * coeff[0])));
        }
        else
        {
            printf("X1 = %.3f+%.3fi\t", (-coeff[1] / (2 * coeff[0])), (sqrt(-dis)) / (2 * coeff[0]));
            printf("X2 = %.3f-%.3fi\n", (-coeff[1] / (2 * coeff[0])), (sqrt(-dis)) / (2 * coeff[0]));
        }
    }
}
void slv_3rddegpoly() // To solve qubic equation(a*x^3 +b*x^2 +cx +d = 0)
{
    float coeff[4] = {0}, dis = 0;
    double complex w, x1, x2, x3, C, C1, p, q, delta, l, u;
    printf("Enter the coefficients of the equation(a*X^3 +b*X^2 +c*X +d = 0): \n");

    inputpoly(3, coeff);

    if (coeff[0] == 0)
        printf("Math ERROR\n");
    else
    {
        dis = 18 * coeff[0] * coeff[1] * coeff[2] * coeff[3] - 4 * coeff[1] * coeff[1] * coeff[1] * coeff[3] +
              coeff[1] * coeff[1] * coeff[2] * coeff[2] - 4 * coeff[0] * coeff[2] * coeff[2] * coeff[2] -
              27 * coeff[0] * coeff[0] * coeff[3] * coeff[3];
        C = cbrt(((2 * coeff[1] * coeff[1] * coeff[1] - 9 * coeff[0] * coeff[1] * coeff[2] + 27 * coeff[0] * coeff[0] * coeff[3] +
                   sqrt(pow((2 * coeff[1] * coeff[1] * coeff[1] - 9 * coeff[0] * coeff[1] * coeff[2] +
                             27 * coeff[0] * coeff[0] * coeff[3]),
                            2) -
                        4 * pow((coeff[1] * coeff[1] - 3 * coeff[0] * coeff[2]), 3))) /
                  2));
        C1 = cbrt(((2 * coeff[1] * coeff[1] * coeff[1] - 9 * coeff[0] * coeff[1] * coeff[2] + 27 * coeff[0] * coeff[0] * coeff[3] -
                    sqrt(pow((2 * coeff[1] * coeff[1] * coeff[1] - 9 * coeff[0] * coeff[1] * coeff[2] +
                              27 * coeff[0] * coeff[0] * coeff[3]),
                             2) -
                         4 * pow((coeff[1] * coeff[1] - 3 * coeff[0] * coeff[2]), 3))) /
                   2));
        w = cexp((pi * 2.0 * I) / 3.0);
        p = ((3.0 * coeff[0] * coeff[2]) - (coeff[1] * coeff[1])) / (3.0 * coeff[0] * coeff[0]);
        q = ((2.0 * coeff[1] * coeff[1] * coeff[1]) - (9 * coeff[0] * coeff[1] * coeff[2]) +
             (27.0 * coeff[0] * coeff[0] * coeff[3])) /
            (27.0 * coeff[0] * coeff[0] * coeff[0]);
        delta = csqrt(((cpow(q, 2.0)) / 4.0) + ((cpow(p, 3.0)) / 27.0));
        l = cpow((-q / 2.0 + delta), (1.0 / 3.0));
        u = cpow((-q / 2.0 - delta), (1.0 / 3.0));

        if (dis >= 0)
        {
            x1 = l + u - (coeff[1] / (3.0 * coeff[0]));
            x2 = w * l + cpow(w, 2.0) * u - (coeff[1] / (3.0 * coeff[0]));
            x3 = cpow(w, 2.0) * l + w * u - (coeff[1] / (3.0 * coeff[0]));
            printpolsym(coeff, 3);
            printf("X1 = %.3lf\tX2 = %.3lf\tX3 = %.3lf\n", creal(x1), creal(x2), creal(x3));
        }

        else
        {
            x1 = (-coeff[1] / (3 * coeff[0])) - (1 / (3 * coeff[0])) * C - (1 / (3 * coeff[0])) * C1;
            x2 = (-coeff[1] / (3 * coeff[0])) + ((1 + (sqrt(3)) * I) / (6 * coeff[0])) * C +
                 ((1 - (sqrt(3)) * I) / (6 * coeff[0])) * C1;
            x3 = (-coeff[1] / (3 * coeff[0])) + ((1 - (sqrt(3)) * I) / (6 * coeff[0])) * C +
                 ((1 + (sqrt(3)) * I) / (6 * coeff[0])) * C1;
            printpolsym(coeff, 3);
            printf("X1 = %.3lf\tX2 = %.3lf%+.3lfi\tX3 = %.3lf%+.3lfi\n", creal(x1), creal(x2), cimag(x2), creal(x3), cimag(x3));
        }
    }
}
void inputpoly(const unsigned short k, float *coeff)
/*-It receives the coefficients from the user and stores it in an array
  -Its parameters are the degree of the polynomial and the coefficients array*/
{

    char *coeffo = NULL;
    coeffo = malloc(30);

    for (int i = 0; i < k + 1; ++i)
    {
        printf("%c = ", 'a' + i);
        scanf("%s", coeffo);
        *(coeff + i) = atof(coeffo);
        if (coeff[i] == 0 && *coeffo != '0')
        {
            i--;
            printf("Please enter a number: ");

            continue;
        }
    }
    free(coeffo);
}

void printpolsym(float coeff[], const unsigned short k)
/* -To print the polynomial equation in a symbolic way
-Its parameters are the degree of the polynomial and the coefficients array*/
{
    printf("The roots of the equation: ");
    for (int i = k; i >= 0; --i)
    {

        if (i == 0)
        {
            printf("%+0.2f", coeff[k - i]);
            continue;
        }
        else if (i == 1)
        {
            printf("%+0.2f*X ", coeff[k - i]);
            continue;
        }
        printf("%+0.2f*X^%d ", coeff[k - i], i);
    }
    printf(" = 0 are\n");
}

float det_2(float co[2][2]) // To calculate 2x2 determinant
{
    float det = (co[0][0] * co[1][1]) - (co[0][1] * co[1][0]);
    return det;
}
float det_3(float co[3][3]) // To calculate 3x3 determinant
{
    float submat1[2][2] = {{co[1][1], co[1][2]}, {co[2][1], co[2][2]}};
    float submat2[2][2] = {{co[1][0], co[1][2]}, {co[2][0], co[2][2]}};
    float submat3[2][2] = {{co[1][0], co[1][1]}, {co[2][0], co[2][1]}};
    float det = co[0][0] * det_2(submat1) - co[0][1] * det_2(submat2) + co[0][2] * det_2(submat3);
    return det;
}
float det_4(float co[4][4]) // To calculate 4x4 determinant
{
    float submat1[3][3] = {{co[1][1], co[1][2], co[1][3]}, {co[2][1], co[2][2], co[2][3]}, {co[3][1], co[3][2], co[3][3]}};
    float submat2[3][3] = {{co[1][0], co[1][2], co[1][3]}, {co[2][0], co[2][2], co[2][3]}, {co[3][0], co[3][2], co[3][3]}};
    float submat3[3][3] = {{co[1][0], co[1][1], co[1][3]}, {co[2][0], co[2][1], co[2][3]}, {co[3][0], co[3][1], co[3][3]}};
    float submat4[3][3] = {{co[1][0], co[1][1], co[1][2]}, {co[2][0], co[2][1], co[2][2]}, {co[3][0], co[3][1], co[3][2]}};
    float det = co[0][0] * det_3(submat1) - co[0][1] * det_3(submat2) + co[0][2] * det_3(submat3) - co[0][3] * det_3(submat4);
    return det;
}

void slv_2lineareqns() // To solve a system of 2 linear equations(an*X1 +bn*X2 = cn) Using Cramer's method
{
    float D[2][2] = {0}, D1[2][2] = {0}, D2[2][2] = {0}, coeff[2][3] = {0}, x1 = 0, x2 = 0;
    printf("Enter the coefficients of the system of equations(an*X1 +bn*X2 = cn): \n");
    inputsys(2, coeff);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            D[i][j] = coeff[i][j];
            D1[i][j] = coeff[i][2 - j];
            D2[i][j] = coeff[i][j == 0 ? 0 : 2];
        }
    }
    x1 = det_2(D1) / det_2(D);
    x2 = det_2(D2) / det_2(D);
    printsys(2, coeff);

    if (det_2(D) == 0 || det_2(D) == NAN || fabs(x1) == NAN || fabs(x2) == NAN || fabs(x1) == INFINITY || fabs(x2) == INFINITY)
        printf("has infinite solutions or no solution\n");
    else if (x1 == 0 && x2 == 0)
        printf("only has solution of this system is ZERO solution which is X1 = X2 = 0\n");
    else
    {

        printf("has solutions: \nX1 = %.3f\tX2 = %.3f\n", x1, x2);
    }
}
void slv_3lineareqns() // To solve a system of 3 linear equations(an*X1 +bn*X2 +cn*ْX3 = dn) Using Cramer's method
{
    float D[3][3] = {0}, D1[3][3] = {0}, D2[3][3] = {0}, D3[3][3] = {0}, coeff[3][4] = {0}, x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    printf("Enter the coefficients of the system of equations(an*X1 +bn*X2 +cn*X3 = dn): \n");
    inputsys(3, coeff);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            D[i][j] = coeff[i][j];
            D1[i][j] = coeff[i][j == 0 ? 3 : j];
            D2[i][j] = coeff[i][j == 1 ? 3 : j];
            D3[i][j] = coeff[i][j == 2 ? 3 : j];
        }
    }
    x1 = det_3(D1) / det_3(D);
    x2 = det_3(D2) / det_3(D);
    x3 = det_3(D3) / det_3(D);
    printsys(3, coeff);

    if (det_3(D) == 0 || det_3(D) == NAN || fabs(x1) == NAN || fabs(x2) == NAN || fabs(x3) == NAN || fabs(x1) == INFINITY ||
        fabs(x2) == INFINITY || fabs(x3) == INFINITY)
        printf("has infinite solutions or no solution\n");
    else if (x1 == 0 && x2 == 0 && x3 == 0)
        printf("only has solution is ZERO solution which is X1 = X2 = X3 = 0\n");
    else
    {

        printf("has solutions: \nX1 = %.3f\tX2= %.3f\tX3 = %.3f\n", x1, x2, x3);
    }
}

void slv_4lineareqns() // To solve a system of 4 linear equations(an*X1 +bn*X2 +cn*ْX3 +dn*X4 = en) Using Cramer's method
{
    float D[4][4], D1[4][4], D2[4][4], D3[4][4], D4[4][4], coeff[4][5] = {0}, x1, x2, x3, x4;
    printf("Enter the coefficients of the system of equations(an*X1 +bn*X2 +cn*X3 +dn*X4 = en): \n");
    inputsys(4, coeff);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            D[i][j] = coeff[i][j];
            D1[i][j] = coeff[i][j == 0 ? 4 : j];
            D2[i][j] = coeff[i][j == 1 ? 4 : j];
            D3[i][j] = coeff[i][j == 2 ? 4 : j];
            D4[i][j] = coeff[i][j == 3 ? 4 : j];
        }
    }
    x1 = det_4(D1) / det_4(D);
    x2 = det_4(D2) / det_4(D);
    x3 = det_4(D3) / det_4(D);
    x4 = det_4(D4) / det_4(D);
    printsys(4, coeff);
    if ((det_4(D) == 0 || det_4(D) == NAN) || x1 == NAN || x2 == NAN || x3 == NAN || x4 == NAN || x1 == INFINITY ||
        x2 == INFINITY || x3 == INFINITY || x4 == INFINITY)
        printf("has infinite solutions or no solution\n");
    else if (x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0)
        printf("only has solution is ZERO solution which is X1 = X2 = X3 = X4 = 0\n");
    else
    {

        printf("has solutions: \nX1 = %.3f \tX2 = %.3f \tX3 = %.3f \tX4 = %.3f \n", x1, x2, x3, x4);
    }
}
void inputsys(const unsigned short k, float coeff[k][k + 1])
/*-It receives the coefficients from the user and stores it in an array
        -Its parameters are the order of the system and the coefficients array*/
{
    char *coeffo = NULL;
    coeffo = malloc(30);

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k + 1; ++j)
        {
            float *r = &coeff[i][j];

            printf("%c%d = ", 'a' + j, i + 1);
            scanf("%s", coeffo);
            *r = atof(coeffo);
            if (coeff[i][j] == 0 && *coeffo != '0')
            {
                i--;
                printf("Please enter a number: ");

                continue;
            }
        }
    }
    free(coeffo);
}

void printsys(const unsigned short k, float coeff[k][k + 1]) /*-To print the system of linear equations in a symbolic way
                                                               -Its parameters are the order of the system and the coefficients array*/
{
    printf("\nThe system:\n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%+.1f*X%d ", coeff[i][j], (j + 1));
            if (j == k - 1)
            {
                printf(" = %.2f\n", coeff[i][k]);
            }
        }
    }
}
