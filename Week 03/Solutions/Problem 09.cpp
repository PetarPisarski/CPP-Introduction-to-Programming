#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

const double EPSILON = 1e-9;

void dimensionOne();
void dimensionTwo();
void dimensionThree();

int main() {
    dimensionOne();
    dimensionTwo();
    dimensionThree();

    return 0;
}

void dimensionOne() {

    double x = 0.0;

    puts("Enter the X coordinate: ");
    cin >> x;

    bool isXEqualZero = (fabs(x) < EPSILON);

    if (isXEqualZero) {
        puts("The point is on the Abscissa!");

    } else {
        if (x > 0.0) {
            puts("The point is in 1 Semi-Plane!");

        } else {
            puts("The point is in 2 Semi-Plane!");

        }
    }
}

void dimensionTwo() {

    double x = 0.0;
    double y = 0.0;

    puts("Enter the X coordinate: ");
    cin >> x;

    puts("Enter the Y coordinate: ");
    cin >> y;

    bool isXEqualZero = (fabs(x) < EPSILON);
    bool isYEqualZero = (fabs(y) < EPSILON);

    if (isXEqualZero && isYEqualZero) {
        puts("The point is on the Center!");

    } else {
        if (isYEqualZero) {
            puts("The point is on the Abscissa!");

        } else if (isXEqualZero) {
            puts("The point is on the Ordinate!");

        } else {
            if (x > 0.0 && y > 0.0) {
                puts("The point is in 1 Quadrant!");

            } else if (x < 0.0 && y > 0.0) {
                puts("The point is in 2 Quadrant!");

            } else if (x < 0.0 && y < 0.0) {
                puts("The point is in 3 Quadrant!");

            } else {
                puts("The point is in 4 Quadrant!");

            }
        }
    }
}

void dimensionThree() {

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    puts("Enter the X coordinate: ");
    cin >> x;

    puts("Enter the Y coordinate: ");
    cin >> y;

    puts("Enter the Z coordinate: ");
    cin >> z;

    bool isXEqualZero = (fabs(x) < EPSILON);
    bool isYEqualZero = (fabs(y) < EPSILON);
    bool isZEqualZero = (fabs(z) < EPSILON);

    if (isXEqualZero && isYEqualZero && isZEqualZero) {
        puts("The point is on the Center!\n");

    }
    else if (isYEqualZero && isZEqualZero) {
        puts("The point is on the Abscissa!\n");

    }
    else if (isXEqualZero && isZEqualZero) {
        puts("The point is on the Ordinate!\n");

    }
    else if (isXEqualZero && isYEqualZero) {
        puts("The point is on the Applicate!\n");

    }
    else if (isZEqualZero) {
        puts("The point is in the Semi-Plane Oxy!\n");

    }
    else if (isYEqualZero) {
        puts("The point is in the Semi-Plane Oxz!\n");

    }
    else if (isXEqualZero) {
        puts("The point is in the Semi-Plane Oyz!\n");

    }
    else {
        if (x > 0.0 && y < 0.0 && z > 0.0) {
            puts("The point is in 1 Octant!\n");

        }
        else if (x < 0.0 && y < 0.0 && z > 0.0) {
            puts("The point is in 2 Octant!\n");

        }
        else if (x < 0.0 && y > 0.0 && z > 0.0) {
            puts("The point is in 3 Octant!\n");

        }
        else if (x > 0.0 && y > 0.0 && z > 0.0) {
            puts("The point is in 4 Octant!\n");

        }
        else if (x > 0.0 && y < 0.0 && z < 0.0) {
            puts("The point is in 5 Octant!\n");

        }
        else if (x < 0.0 && y < 0.0 && z < 0.0) {
            puts("The point is in 6 Octant!\n");

        }
        else if (x < 0.0 && y > 0.0 && z < 0.0) {
            puts("The point is in 7 Octant!\n");

        }
        else {
            puts("The point is in 8 Octant!\n");

        }
    }
}