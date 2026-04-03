# Perfect Numbers

This project was developed as a final assignment for the course **CSCB035 – Programming and Discrete Mathematics Lab**.

The project explores the properties of perfect numbers and implements various functions for working with divisors, sets, and numerical relationships, including their connection to Mersenne prime numbers.

---

## Project Description

Perfect numbers are positive integers that are equal to the sum of all their divisors (including 1), excluding the number itself.

### Examples:
- 6 = 1 + 2 + 3
- 28 = 1 + 2 + 4 + 7 + 14

### First eight perfect numbers:
- 6
- 28
- 496
- 8128
- 33 550 336
- 8 589 869 056
- 137 438 691 328
- 2 305 843 008 139 952 128

---

## Theoretical Background

Numbers of the form 2^p - 1 are called **Mersenne numbers**.

Even perfect numbers can be represented in the form:

2^(p-1) * (2^p - 1)

where:
- p is a prime number
- 2^p - 1 is also a prime number (a Mersenne prime)

### Examples:
- 6 = 2^1 * (2^2 - 1)
- 28 = 2^2 * (2^3 - 1)

---

## Functionalities

The project includes the implementation of the following functions:

1. A function that returns the sum of the divisors of a number (excluding the number itself).
2. A function that prints all divisors of a given number (excluding the number itself).
3. A function that computes the intersection of the sets of divisors of two numbers.
4. A function that computes the union of the sets of prime divisors of two numbers.
5. A function that checks whether a number is perfect.
6. A function that prints all perfect numbers within a given interval.
7. A function that prints the first n perfect numbers.
8. A function that stores all perfect numbers in a given interval in an array.
9. A function that stores the first n perfect numbers using the Mersenne number relationship.
10. A function that stores the representation of perfect numbers in the form  
    2^(p-1) * (2^p - 1) as a string (for n <= 8), for example:  
    2^(4-1).(2^5-1)

---

## Implementation Requirements

- Separate compilation must be used.
- All described functions must be implemented, along with any additional helper functions if needed.
- The program must work with numbers in the interval:  
  [0; 2 305 843 008 139 952 128]
- The eighth perfect number must be found:  
  2 305 843 008 139 952 128
- Input data must be properly validated.
- The project is individual and must be submitted according to a schedule provided by the instructor.

---

## Notes

The project combines concepts from:
- programming (functions, arrays, data processing)
- discrete mathematics (divisors, sets, prime numbers)

The goal is to demonstrate both algorithmic thinking and understanding of the mathematical properties behind perfect numbers.