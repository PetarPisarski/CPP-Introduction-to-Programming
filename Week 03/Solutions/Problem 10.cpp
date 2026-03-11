#include <iostream>

using std::cin, std::cout, std::endl;

#define POINTS 20

int main() {
    unsigned int grade = 0;

    cout << "Enter the grade: ";

    if (!(cin >> grade)) {
        puts("Invalid Input!\n");

        return 1;
    }

    if (grade < 2 || grade > 6) {
        puts("Invalid Grade!\n");

        return 2;
    }

    unsigned int points1 = 0;
    unsigned int points2 = 0;
    unsigned int points3 = 0;

    puts("Enter the points of the other 3 Components: ");

    if (!(cin >> points1 >> points2 >> points3)) {
        puts("Invalid Input!\n");

        return 1;
    }

    int condition1 = (points1 <= 40);
    int condition2 = (points2 <= 10);
    int condition3 = (points3 <= 30);

    if (!condition1 || !condition2 || !condition3) {
        puts("Invalid Data for Points!\n");

        return 2;
    }

    unsigned int result = POINTS + points1 + points2 + points3;

    switch (grade) {
        case 2:
            cout << "Available Grade: " << (result < 50 ? "Yes" : "No") << endl;

            break;

        case 3:
            cout << "Available Grade: " << (result >= 50 && result <= 60 ? "Yes" : "No") << endl;

            break;

        case 4:

            cout << "Available Grade: " << (result >= 61 && result <= 70 ? "Yes" : "No") << endl;

            break;

        case 5:
            cout << "Available Grade: " << (result >= 71 && result <= 80 ? "Yes" : "No") << endl;

            break;

        case 6:
            cout << "Available Grade: " << (result >= 81 && result <= 100 ? "Yes" : "No") << endl;

            break;
    }

    return 0;
}