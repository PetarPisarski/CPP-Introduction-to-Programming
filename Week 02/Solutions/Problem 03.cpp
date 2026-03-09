#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int numberOne = 13;
    int numberTwo = 15;

    cout << "The numbers before the switch: " << numberOne << " and " << numberTwo << endl;

    int tempNumber = numberOne;
    numberOne = numberTwo;
    numberTwo = tempNumber;

    cout << "The numbers after the switch: " << numberOne << " and " << numberTwo << endl;

    //Without a third variable:

    puts("The switch without a third variable: ");

    int firstNumber;
    int secondNumber;

    cout << "The numbers before the switch: " << numberOne << " and " << numberTwo << endl;

    firstNumber = secondNumber + firstNumber;
    secondNumber = firstNumber - secondNumber;
    firstNumber = firstNumber - secondNumber;

    cout << "The numbers after the switch: " << numberOne << " and " << numberTwo << endl;

    return 0;
}