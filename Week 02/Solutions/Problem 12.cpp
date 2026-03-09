#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int numberOne = 0;
    int numberTwo = 0;

    puts("Enter your first Number: ");
    cin >> numberOne;

    puts("Enter your second Number: ");
    cin >> numberTwo;

    int minNumber = (numberOne < numberTwo) ? numberOne : numberTwo;
    int maxNumber = (numberOne > numberTwo) ? numberOne : numberTwo;

    /*
    IF I CANNOT USE ternary operator

    minNumber = (numberOne < numberTwo) * numberOne + (numberOne >= numberTwo) * numberTwo;
    maxNumber = (numberOne > numberTwo) * numberOne + (numberOne <= numberTwo) * numberTwo;

    */

    cout << "The min number is: " << minNumber << endl;
    cout << "The max number is: " << maxNumber << endl;

    return 0;
}