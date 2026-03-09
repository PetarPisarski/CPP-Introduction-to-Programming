#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

int main () {

    double numberOne;
    double numberTwo;
    double numberThree;

    puts("Please enter the first number: ");
    cin >> numberOne;
    puts("Please enter the second number: ");
    cin >> numberTwo;
    puts("Please enter the third number: ");
    cin >> numberThree;

    double arithmeticMean = (numberOne + numberTwo + numberThree) / 3;
    double geometricMean = cbrt(numberOne * numberTwo * numberThree);
    double harmonicMean = 3.0/ ((1.0 / numberOne) + (1.0 / numberTwo) + (1.0 / numberThree));
    double quadraticMean = sqrt((pow(numberOne, 2) + pow(numberTwo, 2) + pow(numberThree, 2))/3.0);


    cout << "The arithmetic mean is:" << arithmeticMean << endl;
    cout << "The geometric mean is:" << geometricMean << endl;
    cout << "The harmonic mean is:" << harmonicMean << endl;
    cout << "The quadratic mean is:" << quadraticMean << endl;

    return 0;
}