#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

const double EPSILON    =   1E-9;

void solveEquation1();
void solveQuadraticEquation();
void solveEquation3();


int main() {
    solveEquation1();
    solveQuadraticEquation();
    solveEquation3();

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

void solveEquation3() {
    double  a   =   0.0;
    double  b   =   0.0;
    double  c   =   0.0;
    double  d   =   0.0;

    cout << "Enter coefficient A: " << endl;
    cin >> a;
    cout << "Enter coefficient B: " << endl;
    cin >> b;
    cout << "Enter coefficient C: " << endl;
    cin >> c;
    cout << "Enter coefficient D: " << endl;
    cin >> d;

    unsigned short int  bit1 = (fabs(a) >= EPSILON);
    unsigned short int  bit2 = (fabs(b) >= EPSILON);
    unsigned short int  bit3 = (fabs(c) >= EPSILON);
    unsigned short int  bit4 = (fabs(d) >= EPSILON);

    unsigned short int  number  =   0;

    number  = ((number & ~(1 << 0)) | (bit1 << 0));
    number  = ((number & ~(1 << 1)) | (bit2 << 1));
    number  = ((number & ~(1 << 2)) | (bit3 << 2));
    number  = ((number & ~(1 << 3)) | (bit4 << 3));


    // 0 Case:   A == 0, B == 0, C == 0, D == 0  ->  x ∈ R			        0000
    // 1 Case:   A != 0, B == 0, C == 0, D == 0  ->  x ∈ R			        0001
    // 2 Case:   A == 0, B != 0, C == 0, D == 0  ->  x ∈ R			        0010
    // 3 Case:   A != 0, B != 0, C == 0, D == 0  ->  x ∈ R			        0011
    // 4 Case:   A == 0, B == 0, C != 0, D == 0  ->  x ∈ R			        0100
    // 5 Case:   A != 0, B == 0, C != 0, D == 0  ->  x = 0			        0101
    // 6 Case:   A == 0, B != 0, C != 0, D == 0  ->  x = 0			        0110
    // 7 Case:   A != 0, B != 0, C != 0, D == 0  ->  x = 0, x = -B / A	    0111
    // 8 Case:   A == 0, B == 0, C == 0, D != 0  ->  x ∈ R			        1000
    // 9 Case:  A != 0, B == 0, C == 0, D != 0  ->  x = 0			        1001
    // 10 Case:  A == 0, B != 0, C == 0, D != 0  ->  x ∈ ∅			        1010
    // 11 Case:  A != 0, B != 0, C == 0, D != 0  ->  x = -B / A		        1011
    // 12 Case:  A == 0, B == 0, C != 0, D != 0  ->  x ∈ R			        1100
    // 13 Case:  A != 0, B == 0, C != 0, D != 0  ->  x = 0, x = -D / C	    1101
    // 14 Case:  A == 0, B != 0, C != 0, D != 0  ->  x = -D / C		        1110
    // 15 Case:  A != 0, B != 0, C != 0, D != 0  ->  x = -B / A, x = -D / C	1111

    switch (number) {
        case 0: cout << "Every real number is a solution!" << endl; break;
        case 1: cout << "Every real number is a solution!" << endl; break;
        case 2: cout << "Every real number is a solution!" << endl; break;
        case 3: cout << "Every real number is a solution!" << endl; break;
        case 4: cout << "Every real number is a solution!" << endl; break;
        case 5: cout << "Solution is: X = " << 0.000 << endl; break;
        case 6: cout << "Solution is: X = " << 0.000 << endl; break;
        case 7: cout << "Solutions are: X = " << 0.000 << ", X = " << -b / a << endl; break;
        case 8: cout << "Every real number is a solution!" << endl; break;
        case 9: cout << "Solution is: X = " << 0.000 << endl; break;
        case 10: cout << "There are no solutions!" << endl; break;
        case 11: cout << "Solution is: X = " << -b / a << endl; break;
        case 12: cout << "Every real number is a solution!" << endl; break;
        case 13: cout << "Solutions are: X = " << 0.000 << ", X = " << -d / c << endl; break;
        case 14: cout << "Solution is: X = " << -d / c << endl; break;
        case 15: cout << "Solutions are: X = " << -b / a << ", X = " << -d / c << endl; break;
    }

}

void solveQuadraticEquation(){
    double  a   =   0.0;
    double  b   =   0.0;
    double  c   =   0.0;

    cout << "Enter coefficient A: " << endl;
    cin >> a;
    cout << "Enter coefficient B: " << endl;
    cin >> b;
    cout << "Enter coefficient C: " << endl;
    cin >> c;


    if (fabs(a) < EPSILON) {
        unsigned int conditionB =   (fabs(b) < EPSILON);
        unsigned int conditionC =   (fabs(c) < EPSILON);

        if (conditionB && conditionC) {
            puts("Every real number is a solution!");

        } else if (conditionB && !conditionC) {
            puts("There are no solutions!");

        } else {
            cout << "Solution is: X = " << ((-c)/b) << endl;

        }
    } else {
        double discriminant =   (b * b) - (4 * a * c);

        if (fabs(discriminant) < EPSILON) {
            cout << "Solution is: X = " << (-b / (2 * a)) << endl;

        } else {
            if (discriminant < 0.0) {
                puts("There are no real solutions!");
            } else {
                cout << "Solution 1 is: X = " << (-b + sqrt(discriminant)) / (2 * a) << endl;
                cout << "Solution 2 is: X = " << (-b - sqrt(discriminant)) / (2 * a) << endl;


            }
        }
    }
}

