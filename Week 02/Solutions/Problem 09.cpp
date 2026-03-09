#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int number;

    puts("Please enter your 4-digit number: ");
    cin >> number;

    int digit1 = number % 10;
    int digit2 = (number / 10) % 10;
    int digit3 = (number / 100) % 10;
    int digit4 = number / 1000;

    int digitsSum = digit1 + digit2 + digit3 + digit4;
    int digitsProduct = digit1 * digit2 * digit3 * digit4;

    cout << "The SUM of the digits is: " << digitsSum << endl;
    cout << "The PRODUCT of the digits is: " << digitsProduct << endl;

    return 0;
}