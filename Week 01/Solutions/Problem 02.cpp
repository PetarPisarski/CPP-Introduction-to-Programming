#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    int number;

    cout << "Please enter your number: " << endl;
    cin >> number;

    number = number + 1;

    cout << "The SUCC result is: " << number << endl;

    return 0;
}