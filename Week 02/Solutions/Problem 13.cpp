#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int numberOne =   0;
    int numberTwo =   0;
    int numberThree =   0;


    puts("Enter the Number 1: ");
    cin >> numberOne;

    puts("Enter the Number 2: ");
    cin >> numberTwo;

    puts("Enter the Number 3: ");
    cin >> numberThree;


    int countPositive = (numberOne > 0) + (numberTwo > 0) + (numberThree > 0);
    int countNegative = (numberOne < 0) + (numberTwo < 0) + (numberThree < 0);

    cout << "The count of the positive numbers is: " << countPositive << endl;
    cout << "The count of the negative numbers is: " << countNegative << endl;

    return 0;
}