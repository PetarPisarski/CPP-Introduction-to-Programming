#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    double  X   =   0.0;
    double  Y   =   0.0;

    puts("Enter your X: ");
    cin >> X;
    puts("Enter your Y: ");
    cin >> Y;


    double partOne = (X * X) / (Y * Y - 1);
    double partTwo = (Y * Y) / (X * X - 1);
    double partThree = 1 / (X * X + Y * Y);
    double partFour = 1 / (X * X - Y * Y);


    double result = (partOne + partTwo + partThree) / partFour;

    cout << "The result is: " << result << endl;

    return 0;
}