#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

#define EPSILON 1e-9

int main() {

    char operation = 'O';

    puts("Enter the operation O: ");

    if (!(cin >> operation)) {
        puts("Invalid Input!");

        return 1;
    }

    double number1 = 0.0;
    double number2 = 0.0;

    puts("Enter the number X: ");
    if (!(cin >> number1)) {
        puts("Invalid Input!");

        return 1;
    }

    puts("Enter the number Y: ");
    if (!(cin >> number2)) {
        puts("Invalid Input!");

        return 1;
    }
    double result = 0.0;

    switch (operation) {
        case '+': result = number1 + number2; break;
        case '-': result = number1 - number2; break;
        case '*': result = number1 * number2; break;

        case '/':
            if (fabs(number2) < EPSILON) {
                puts("Division by Zero!");

                return 1;
            }

            result = number1 / number2;
            break;

        case '^': result = pow(number1, number2); break;

        default:
            puts("Invalid Operation!");

            return 1;
    }

    cout << "The result is: " << result << endl;

    return 0;

}