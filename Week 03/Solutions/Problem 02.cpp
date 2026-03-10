#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    unsigned int number, moveByBits;

    puts("Please enter your number: ");
    cin >> number;
    puts("Please enter by how many bits to move: ");
    cin >> moveByBits;

    cout << number << " moved by " << moveByBits << " to the right is: " << (number >> moveByBits) << endl;
    cout << number << " moved by " << moveByBits << " to the left is: " << (number << moveByBits) << endl;

    return 0;
}