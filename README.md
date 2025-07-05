# Equation Solver

Equation Solver is a C program that helps you solve different types of equations, including:

- Linear equations (ax + b = 0)
- Quadratic equations (ax² + bx + c = 0)
- Cubic equations (ax³ + bx² + cx + d = 0)
- Systems of linear equations (2x2, 3x3, and 4x4) using Cramer's Rule

## Features

- Interactive command-line interface
- Handles real and complex roots for quadratic and cubic equations
- Solves systems of linear equations up to 4 variables
- Symbolic display of input equations and systems
- Input validation for coefficients

## Getting Started

### Prerequisites

- GCC compiler (with support for C99 or later)
- Windows (uses `<conio.h>` for input)

### Building

1. Open a terminal in the project directory.
2. Compile the code using GCC:

   ```sh
   gcc Equation_solver.c -o Equation_solver.exe -lm
   ```

   Or use the provided VS Code task (press `Ctrl+Shift+B` in VS Code).

### Running

Run the executable from the terminal:

```sh
./Equation_solver.exe
```

Follow the on-screen prompts to select the type of equation or system you want to solve.

## Usage

1. **Select Problem Type:**  
   Choose from:

   - 1: Linear equation
   - 2: Quadratic equation
   - 3: Cubic equation
   - 4: System of linear equations

2. **Enter Coefficients:**  
   Enter the coefficients as prompted. For systems, specify the number of equations (2, 3, or 4).

3. **View Results:**  
   The program will display the symbolic equation and its solutions.

4. **Repeat or Exit:**  
   Press `Y` to solve another problem, or any other key to exit.

## Example

```
Please choose the type of problem:
1- Linear equation(a*X +b = 0)
2- Quadratic equation(a*x^2 +b*x +c = 0)
3- Cubic equation(a*x^3 +b*x^2 +cx +d = 0)
4- System of n linear equations(an*X1 +bn*X2 +..... = c)
Press the corresponding number to choose the problem type

2
Enter the coefficients of the equation(a*x^2 +b*X +c = 0):
a = 1
b = -3
c = 2
The roots of the equation: +1.00*X^2 -3.00*X +2.00 = 0 are
X1 = 1.000	X2 = 2.000
```

## Code Structure

- [`Equation_solver.c`](Equation_solver.c): Main source code containing all logic and functions.

## Limitations

- Only supports up to 4x4 systems of linear equations.
- Uses Cramer's Rule, which may not be efficient for large systems.
- Uses `<conio.h>`, which is specific to Windows.

## Authors

- [Hamdi Emad](https://github.com/HamdiEmad)
- [Hamed Islam](https://github.com/hamedislam)
- [Hazem Sherif](https://github.com/HazemHHHH)

## License

This project is open source and available under the MIT License.

## Additional Resources

- [Programme description and documentation](https://drive.google.com/drive/folders/1Ao8VSq828yuhiFK1vuH1_FHVUhUTao3v?hl=ar)
