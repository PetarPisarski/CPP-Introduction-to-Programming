#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    char character  = '\0';

    puts("Please enter your character: ");
    if (!(cin >> character)) {
        puts("Invalid Input!");

        return 1;
    }


    if (character >= 'A' && character <= 'Z') {
        puts("Your character is Uppercase");
    }else if (character >= 'a' && character <= 'z') {
        puts("Your character is Lowercase");
    }else if (character >= '0' && character <= '9') {
        puts("Your character is a Digit");
    }

    return 0;
}