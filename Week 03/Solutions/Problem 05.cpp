#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int a,b,x;

    puts("Please set your interval");
    puts("Enter A: ");
    cin >> a;
    puts("Enter B: ");
    cin >> b;

    puts("Now enter your number to see if it is in the Interval: ");
    cin >> x;1

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    if (x > a) {
        cout << x << " is bigger than " << a << endl;

        if (x < b) {
            cout << x << " is smaller than " << b << endl;
            puts("Your number is in the Interval");
        }
    }else {
        puts("Your number is not in the Interval");
    }

    return 0;
}