# Quadratic Equation Solver

## Description

This repository contains a simple C++ program for solving quadratic equations of the form `ax^2 + bx + c = 0`. The program allows users to input the coefficients of a quadratic equation and computes the roots based on the discriminant.

#Code Overview

`parseQuadraticCoefficients`

This function extracts the coefficients `a`,`b`, and `c` from a string input representing a quadratic equation. It uses regular expressions to match and parse the equation, handling various formats and spacing issues.

Function Signature

    bool parseQuadraticCoefficients(const string& input, double& a, double& b, double& c);

Input:

  `input` (const string&): The string containing the quadratic equation.

  `a`, `b`, `c` (double&): References to store the parsed coefficients.
  
Output:

Returns `true` if the input is correctly formatted and the coefficients are successfully parsed; otherwise, `false`.

`main`

The `main` function serves as the entry point of the program. It prompts the user to enter a quadratic equation, parses the coefficients, computes the discriminant, and determines the nature of the roots. It then displays the results.

Function Flow

  1.User Input: Prompts the user to input a quadratic equation.

  2.Parsing: Uses parseQuadraticCoefficients to extract coefficients.

  3.Discriminant Calculation: Computes the discriminant (Δ = b^2 - 4ac)

  4.Root Calculation: Determines the nature of the roots based on the discriminant:

    Two Distinct Real Roots: When `Δ > 0`.
  
    One Real Root (Repeated): When `Δ = 0`.
  
    Two Complex Roots: When `Δ < 0`.
  
  5.Output: Displays the coefficients, discriminant, and the roots of the quadratic equation.
  
## Usage

![Screenshot (38)_LI](https://github.com/user-attachments/assets/a76f6a07-8bcb-4d33-a600-742531d740b6)


## Notes

Ensure the input follows the format closely. Extra spaces or incorrect formats might lead to parsing errors.

Feel free to contribute to the repository or open issues if you encounter problems or have suggestions for improvements.
