#include "functions.c"

// Function to display the main menu
void print_menu()
{
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*                  Equation Solver System                  *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*       1. Linear equation (a*X + b = 0)                   *\n");
    printf("*       2. Quadratic equation (a*x^2 + b*x + c = 0)        *\n");
    printf("*       3. Cubic equation (a*x^3 + b*x^2 + c*x + d = 0)    *\n");
    printf("*       4. System of n linear equations                    *\n");
    printf("*       5. Exit                                            *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("  Enter your choice: ");
}

int main(void)
{
    while (1)
    {
        print_menu();

        char c = 0, t = 0;
        int k;
        t = getch();       // Get user's menu choice (prevent pressing Enter)
        printf("%c\n", t); // Printing the pressed key

        switch (t)
        {
        case ('1'):
            slv_1stdegpoly(); // Solve linear equation
            break;
        case ('2'):
            slv_2nddegpoly(); // Solve quadratic equation
            break;
        case ('3'):
            slv_3rddegpoly(); // Solve cubic equation
            break;
        case ('4'): // Ask the user how many equations to solve
            printf("Please enter the number of equations you want to solve: ");
            scanf("%d", &k);
            solve_lineareqns(k); // Solve system of linear equations
            break;
        case ('5'): // Exit the program
            printf("Exiting...\n");
            return 0;
        default: // Handle invalid input
            printf("Invalid choice! Please try again.\n");
            break;
        }
        printf("\nPress any key to return to the menu, or 'N' to exit.\n");
        c = getch();
        if (c == 'N' || c == 'n')
            break;
    }
    return 0;
}