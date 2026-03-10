#include <iostream>

using std::cin, std:: cout, std::endl;

int main() {

    unsigned int number;

    puts("Please enter your number: ");
    if (!(cin >> number)) {
        puts("Invalid Input!");

        return 1;
    }

    unsigned int leastSignificantBit = number & 1;
    unsigned int mostSignificantBit = (number >> (sizeof(number) * 8 - 1)) & 1;

    cout << "The least significant bit of  " << number << " is " << leastSignificantBit << endl;
    cout << "The most significant but of " << number << " is " << mostSignificantBit << endl;

    return 0;
}