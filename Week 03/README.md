# Week 3 - Bitwise Operations. Types of Programs. Branching Execution. `if` and `switch` Operators. Scope.



## Task 1 (Bitwise Operations 1)

Create a program that reads the values of 2 non-negative integers `x` and `y` and prints to the standard output the result of the following bitwise operations:

- bitwise negation *NOT* of each of them
- bitwise conjunction *AND* between them
- bitwise disjunction *OR* between them
- bitwise exclusive disjunction *XOR* between them

---

## Task 2 (Bitwise Operations 2)

Create a program that reads the values of 1 non-negative integer `z` and a non-negative integer `n` and prints to the standard output the result of the following bitwise operations:

- bitwise shift to the left by `n` positions
- bitwise shift to the right by `n` positions

---

## Task 3 (Special Bits)

Create a program that reads the value of a non-negative integer `n` and prints to the standard output the least significant bit and the most significant bit in the binary representation of the number `n`.

---

## Task 4 (Recognized Symbol)

Create a program that reads a symbol from the standard input and prints to the standard output:

- `"Uppercase Letter"`, if the symbol is an uppercase Latin letter;
- `"Lowercase Letter"`, if the symbol is a lowercase Latin letter;
- `"Number"`, if the symbol is a digit;
- `"Other"`, if it is another symbol.

---

## Task 5 (Interval)

Create a program that reads the values of two integers `a` and `b`, which will represent the closed interval `[a, b]`. If the values are invalid, print an error message to the standard output. Then read a number `x`. Depending on the value of `x`, print to the standard output:

- `"Smaller than a!"`, if `x < a`
- `"In the interval!"`, if `a ≤ x ≤ b`
- `"Bigger than b!"`, if `x > b`

---

## Task 6 (Point in a Circle)

Create a program that reads the coordinates of a point, the coordinates of the center of a circle, and the length of its radius and determines whether the point lies inside the circle, on the circle itself, or outside the circle. On the first line of the standard input read the three numbers describing the circle `x0`, `y0`, `r`, and on the second line read two numbers `x` and `y`, which are the coordinates of the point. The corresponding results from the program should be `Inside the Circle!`, `On the Circle!`, `Outside the Circle!`.

---

## Task 7 (Equations)

Create a program that finds the solutions of the following equations given the coefficients, considering all possible cases:

- ax + b = 0
- ax^2 + bx + c = 0
- (ax + b)(cx + d) = 0

---

## Task 8 (Rectangles)

Create a program that reads the coordinates of 2 rectangles whose sides are parallel to the coordinate axes of a Cartesian coordinate system. A rectangle is described by four real values – the coordinates of its upper left and lower right corners. The program should check whether the rectangles have at least one common point and print the result to the standard output.

---

## Task 9 (Point in a Coordinate System)

Create a program that checks the position of a point, given by its coordinates from the standard input, relative to a coordinate system, printing the corresponding message to the standard output:

- in the one-dimensional case, in which half-line or on the axis it lies
- in the two-dimensional case, in which quadrant or on which axis it lies
- in the three-dimensional case, in which octant or on which axis it lies

---

## Task 10 (Algebra)

The end of the summer session has arrived and everyone is eagerly awaiting the exam in Higher Algebra. As we well know, Associate Professor Bozhilov has the following grading scheme:

- points from theoretical quizzes – 0 - 20 points
- points from the written exam with problems – 0 - 40 points
- points from the oral exam on a developed topic – 0 - 10 points
- points from the oral exam on proofs – 0 - 30 points

The grading scale is the following (we assume that `x` is the number of points of the student):

- `x < 50` -> *Fail 2.00*
- `50 ≤ x ≤ 60` -> *Satisfactory 3.00*
- `60 < x ≤ 70` -> *Good 4.00*
- `70 < x ≤ 80` -> *Very Good 5.00*
- `80 < x ≤ 100` -> *Excellent 6.00*

Jessica is taking the Higher Algebra exam and wants to calculate what result she must obtain from the written exam and the oral exam in order to achieve a specific grade. She is a smart girl and already has 20 points from the theoretical quizzes.

The grade that Jessica wants to achieve should be entered from the standard input. On the next line, enter her points from the remaining three components of the grading scheme. Then print to the standard output whether Jessica would obtain the grade she wants. Perform a check for invalid data.

---

## Task 11 (Point in a Triangle)

Create a program that reads the coordinates of a point from the two-dimensional Cartesian coordinate system, as well as the coordinates of the vertices of a triangle. The standard output should indicate whether the point belongs to the triangle or does not belong to the triangle.

---

## Task 12 (Transformed Number)

Create a program that reads a three-digit number from the standard input and performs the following operations on its digits:

- If the digit is even, replace it with the remainder of the digit modulo 3.
- If the digit is odd, replace it with the remainder of the digit modulo 2.

Print to the standard output the number after the transformation.

---

## Task 13 (Simple Calculator)

Create a program that reads two numbers `X` and `Y` and an operation `O` from the standard input and prints the result of applying the operation `O` to the numbers `X` and `Y` to the standard output. The numbers are real-valued, and the operations are addition, subtraction, multiplication, division, and exponentiation.