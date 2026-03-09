#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

/*
I know that functions are yet to be discussed but I used functions
in order the code to be useful in the future
*/

    void distanceInOneDimension();
    void distanceInTwoDimension();
    void distanceInThreeDimension();

int main() {

    distanceInOneDimension();
    distanceInTwoDimension();
    distanceInThreeDimension();

    return 0;
}

void distanceInOneDimension() {

    double x1 = 0.0;
    double x2 = 0.0;

    puts("Enter the coordinates of Point 1: ");
    cin >> x1;
    puts("Enter the coordinates of Point 2: ");
    cin >> x2;

    cout << "The distance is: " << fabs(x1 - x2) << endl;

}

void distanceInTwoDimension() {

    double x1 = 0.0;
    double y1 = 0.0;

    double x2 = 0.0;
    double y2 = 0.0;


    puts("Enter the coordinates of Point 1: ");
    cin >> x1 >> y1;
    puts("Enter the coordinates of Point 2: ");
    cin >> x2 >> y2;

    cout << "The distance is: " << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) << endl;

}

void distanceInThreeDimension() {
    double x1 = 0.0;
    double y1 = 0.0;
    double z1 = 0.0;

    double x2 = 0.0;
    double y2 = 0.0;
    double z2 = 0.0;


    puts("Enter the coordinates of Point 1: ");
    cin >> x1 >> y1 >> z1;
    puts("Enter the coordinates of Point 2: ");
    cin >> x2 >> y2 >> z2;

    cout << "The distance is: " << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2)) << endl;

}