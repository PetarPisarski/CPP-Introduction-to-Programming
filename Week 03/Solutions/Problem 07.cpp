#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

const double EPSILON    =   1e-9;

void solveEquation1();
void solveEquation2();
void solveEquation3();


int main() {



    return 0;
}

void solveLinearEquation1() {
    double  a   =   0.0;
    double  b   =   0.0;

    puts("Enter coefficient A: ");
    cin >> a;
    puts("Enter coefficient A: ");
    cin >> b;

    unsigned short int  bit1    =   (fabs(a) >= EPSILON);
    unsigned short int  bit2    =   (fabs(b) >= EPSILON);

    unsigned short int  number  =   0;

    number  =   ((number & ~(1 << 0)) | (bit1 << 0));
    number  =   ((number & ~(1 << 1)) | (bit2 << 1));


    // 1 Case: A == 0, B == 0 -> x ∈ R
    // 2 Case: A != 0, B == 0 -> x = 0
    // 3 Case: A == 0, B != 0 -> x ∈ ∅
    // 4 Case: A != 0, B != 0 -> x = -B / A

    switch (number) {
        case 0:     printf("Every real number is a solution!\n");   break;
        case 1:     printf("Solution is: X = %lf\n", 0.000);        break;
        case 2:     printf("There are no solutions!\n");            break;
        case 3:     printf("Solution is: X = %lf\n", -b / a);       break;
        default:    break;
    }
}