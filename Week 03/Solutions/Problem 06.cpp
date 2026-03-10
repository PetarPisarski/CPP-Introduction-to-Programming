#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

const double EPSILON = 1e-9;

int main() {
    double xCenter  =   0.0;
    double yCenter  =   0.0;

    puts("Enter the coordinates of center of the circle: ");

    if (!(cin >> xCenter >> yCenter)) {
        puts("Invalid Input!");

        return 1;

    }

    double radius   =   0.0;

    puts("Enter the radius of the circle: ");

    if (!(cin >> radius)) {
        puts("Invalid Input!");

        return 1;

    }


    double xPoint   =   0.0;
    double yPoint   =   0.0;

    puts("Enter the coordinates of your point: ");

    if (!(cin >> xPoint >> yPoint)) {
        puts("Invalid Input!");

        return 1;

    }


    double xDistance    =   pow(fabs(xPoint - xCenter), 2);
    double yDistance    =   pow(fabs(yPoint - yCenter), 2);
    double  distance    =   sqrt(xDistance + yDistance);

    if (fabs(distance - radius) <= EPSILON) {
        cout << "Your point is on the circle" << endl;
    } else {
        if (distance < radius) {
            cout << "Your point is inside of the circle" << endl;
        } else {
            cout << "Your point is outside of the circle" << endl;
        }
    }


    return 0;
}