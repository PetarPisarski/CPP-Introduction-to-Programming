#include <iostream>

using std::cin, std::cout, std::endl;

int  main() {

    char letter;

    puts("Please enter the letter you want to transform into lowercase: ");
    cin >> letter;

    cout << "The letter you've entered: " << (char)(letter + 32) << endl;

    return 0;
}