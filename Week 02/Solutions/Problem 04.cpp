#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int x,y;
    cin >> x >> y;

    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    cout << x << " % " << y << " = " << x % y << endl;

    cout << x << " < " << y << " = " << (x < y) << endl;
    cout << x << " > " << y << " = " << (x > y) << endl;

    cout << x << " <= " << y << " = " << (x <= y) << endl;
    cout << x << " >= " << y << " = " << (x >= y) << endl;

    cout << x << " == " << y << " = " << (x == y) << endl;
    cout << x << " != " << y << " = " << (x != y) << endl;

    cout << x << " && " << y << " = " << (x && y) << endl;
    cout << x << " || " << y << " = " << (x || y) << endl;


    return 0;
}