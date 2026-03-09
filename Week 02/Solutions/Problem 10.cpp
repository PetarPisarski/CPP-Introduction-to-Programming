#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    int year = 0;

    puts("Enter your year: ");
    cin >> year;

    int condition1 = ((year % 4 == 0) && (year % 100 != 0));
    int condition2 = (year % 400 == 0);

    cout << "Leap Year: " << condition1 || condition2;

    return 0;
}