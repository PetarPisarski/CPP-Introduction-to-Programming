#include <iostream>

using std::cin, std::cout, std::endl;

int main() {

    float radius;
    const float PI = 3.141593;

    puts("Enter the radius of your cicle: ");
    cin >> radius;

    double circumference = 2 * PI * radius;
    double area = PI * radius * radius;

    cout << "The circumference of the circle is: " << circumference << endl;
    cout << "The area of the cirlce is: " << area << endl;

    return 0;
}