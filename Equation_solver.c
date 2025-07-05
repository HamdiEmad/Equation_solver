#include <complex.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159
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

int main(void)
{
    while (1) // To repeat the program until a terminating statement
    {
        printf("Please choose the type of problem:\n");
        printf("1- Linear equation(a*X +b = 0)\n");
        printf("2- Quadratic equation(a*x^2 +b*x +c = 0)\n");
        printf("3- Cubic equation(a*x^3 +b*x^2 +cx +d = 0)\n");
        printf("4- System of n linear equations(an*X1 +bn*X2 +..... = c)\n");
        printf("Press the corresponding number to choose the problem type\n\n");
        char c = 0, t = 0, k;
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
            printf("Please enter the number of equations you want to solve: ");
            scanf("%d", &k);
            solve_lineareqns(k);
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
void inputpoly(int k, float *coeff)
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

void printpolsym(float coeff[], int k)
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
double det(int k, double co[k][k]) // To calculate determinants
{
    double submat[k][k - 1][k - 1], det1 = 0.0;
    if (k == 1)
        return co[0][0];
    else if (k == 2)
        return (co[0][0] * co[1][1]) - (co[0][1] * co[1][0]);

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k - 1; ++j)
        {
            for (int t = 0, y = 0; y < k - 1; ++t, ++y)
            {
                if (t == i)
                    ++t;

                submat[i][j][y] = co[j + 1][t];
            }
        }
        det1 += pow(-1, i) * co[0][i] * det(k - 1, submat[i]);
    }

    k--;
    return det1;
}

void solve_lineareqns(int k) // solving system of linear equations using Cramer's method

{
    printf("Enter the coefficients of the system of %d linear equations: \n", k);
    double Dn[k][k][k], coeff[k][k + 1], D[k][k], R[k];
    inputsys(k, coeff);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            for (int t = 0; t < k; ++t)
            {
                D[j][t] = coeff[j][t];
                Dn[i][j][t] = coeff[j][t == i ? k : t];
                R[i] = det(k, Dn[i]) / det(k, D);
            }
        }
    }

    printsys(k, coeff);
    if (det(k, D) == 0 || det(k, D) == NAN)
        printf("\nhas infinite solutions or no solution\n");
    else
    {
        printf("\nhas solutions: ");
        for (int i = 0; i < k; ++i)
        {
            printf("\nX%d = %-+15.3lf", i + 1, R[i]);
        }
        printf("\n");
    }
}
void inputsys(int k, double coeff[k][k + 1])
/*-It receives the coefficients from the user and stores it in an array
        -Its parameters are the order of the system and the coefficients array*/
{
    char *coeffo = NULL;
    coeffo = malloc(30);

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k + 1; ++j)
        {
            double *r = &coeff[i][j];

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

void printsys(int k, double coeff[k][k + 1]) /*-To print the system of linear equations in a symbolic way
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
