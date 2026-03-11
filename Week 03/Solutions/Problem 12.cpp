#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int number;

    puts("Please enter your 3-digit number: ");
    if (!(cin >> number)) {
        puts("Invalid input!");

        return 1;
    }

    if (number < 100 || number > 999) {
        puts("Invalid input!");

        return 1;
    }

    int digit1 = number % 10;
    int digit2 = (number / 10) % 10;
    int digit3 = (number / 100) % 10;

    if (digit1 % 2 == 0) {
        digit1 = digit1 % 3;
    }else {
        digit1 = digit1 % 2;
    }

    if (digit2 % 2 == 0) {
        digit2 = digit2 % 3;
    }else {
        digit2 = digit2 % 2;
    }

    if (digit3 % 2 == 0) {
        digit3 = digit3 % 3;
    }else {
        digit3 = digit3 % 2;
    }

    int resultNumber = digit1 + digit2*10 + digit3*100;

    cout << "The result is " << resultNumber << endl;

    return 0;

}