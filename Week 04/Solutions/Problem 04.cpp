#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    unsigned int n,r;

    puts("Please enter your number, the bit that you want to change to 0: ");
    if (!(cin >> n >> r)) {
        puts("Invalid Input!");

        return 1;
    }

    n = (n & ~(1 << r));

    cout << "The new number is: " << n << endl;

    return 0;
}