# A-Simple-Calculator-Program

This Simple Calculator Program which converts infix expressions to postfix and then evaluates the postfix expression using a stack.

## Table of Contents

- [Overview](#overview)
- [Dependencies](#dependencies)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [License](#license)

## Overview

This C++ program provides functions to convert an infix expression to a postfix expression and evaluate it. It uses a custom stack implementation (`Stackt`) to perform the conversions and calculations.

## Dependencies

- C++ compiler
- Standard C++ libraries

## Usage

1. Compile the program using a C++ compiler (e.g., `g++`).
2. Run the compiled executable.
3. Enter an infix expression when prompted.
4. The program will output the corresponding postfix expression and the result of the evaluation.

## Code Structure

- `main.cpp`: Contains the main program logic for reading user input, converting infix to postfix, and evaluating the postfix expression.
- `Stackt.h`: Header file for the `Stackt` template class, which provides stack operations.
- `Stackt.cpp`: Implementation file for the `Stackt` template class.
