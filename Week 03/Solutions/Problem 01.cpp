#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    unsigned int x,y;

    puts("Please enter your X and Y: ");
    cin >> x >> y;

    cout << "The NOT of X is: " << ~x << endl;
    cout << "The NOT of Y is: " << ~y << endl;

    cout << "X AND Y is: " << (x & y) << endl;
    cout << "X OR Y is: " << (x | y) << endl;
    cout << "X XOR Y is: " << (x ^ y) << endl;

    return 0;
}