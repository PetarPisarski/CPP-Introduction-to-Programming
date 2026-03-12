#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    unsigned int n,s;

    puts("Please enter your number and the bit that you would like to see: ");
    if (!(cin >> n >> s)) {
        puts("Invalid Input!");

        return 1;
    }

    unsigned int bitOnS = (n >> s) & 1;

    cout << "The bit of " << n << " on " << s << " is " << bitOnS << endl;

    return 0;

}