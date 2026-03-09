#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int number;
    float numberFloat;
    double numberDouble;

    char character;

    cin >> number >> numberFloat >> numberDouble >> character;

    cout << "The int is = " << number << endl;
    cout << "The float is = " << numberFloat << endl;
    cout << "The double is = " << numberDouble << endl;
    cout << "The char is = " << character << endl;

    return 0;
}