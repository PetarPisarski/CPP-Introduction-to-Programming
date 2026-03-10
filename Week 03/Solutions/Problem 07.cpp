#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

const double EPSILON    =   1E-9;

void solveEquation1();
void solveEquation2();
void solveEquation3();


int main() {
    solveEquation1();


    return 0;
}

void solveEquation1() {
    double  a   =   0.0;
    double  b   =   0.0;

    puts("Enter coefficient A: ");
    cin >> a;
    puts("Enter coefficient B: ");
    cin >> b;

    unsigned short int  bit1 = (fabs(a) >= EPSILON);
    unsigned short int  bit2 = (fabs(b) >= EPSILON);

    unsigned short int  number  =   0;

    number  =   ((number & ~(1 << 0)) | (bit1 << 0));
    number  =   ((number & ~(1 << 1)) | (bit2 << 1));


    // 1 Case: A == 0, B == 0 -> x ∈ R          0000
    // 2 Case: A != 0, B == 0 -> x = 0          0001
    // 3 Case: A == 0, B != 0 -> x ∈ ∅          0010
    // 4 Case: A != 0, B != 0 -> x = -B / A     0011

    switch (number) {
        case 0:     cout << "Every real number is a solution" << endl;   break;
        case 1:     cout << "The Solution is X = " << 0 << endl;    break;
        case 2:     cout << "There are no real solutions" << endl;    break;
        case 3:     cout << "The Solution is X = " << ((-b)/a) << endl;   break;
        default:    break;
    }
}