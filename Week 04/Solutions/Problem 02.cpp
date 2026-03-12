#include <iostream>

using std::cout, std::cin, std::endl;

int main() {

    unsigned int n,s,r;

    puts("Please enter your number, the bit that you want to change to 0, and the bit that you want to change to 1: ");
    if (!(cin >> n >> s >> r)) {
        puts("Invalid Input!");

        return 1;
    }

    n = (n & ~(1 << s));
    n = (n |  (1 << r));

    cout << "The new number is: " << n << endl;


    return 0;
}