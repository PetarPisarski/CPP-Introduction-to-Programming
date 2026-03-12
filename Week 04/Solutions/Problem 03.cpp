#include <iostream>

using std::cout, std::cin, std::endl;

int main() {

    unsigned int number;


    puts("Please enter your number: ");
    if (!(cin >> number)) {
        puts("Invalid input");

        return 1;
    }

    if ((number & 1) != 1) {
        puts("Indeed your number is even");

    }else {
        puts("Indeed your number is odd");
    }


    return 0;
}