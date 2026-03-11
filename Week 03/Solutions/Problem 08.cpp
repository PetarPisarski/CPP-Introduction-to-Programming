#include  <iostream>

using std::cin, std::cout, std::endl;


int main() {

    double rectangle1X1 =   0.0;
    double rectangle1Y1 =   0.0;
    double rectangle1X2 =   0.0;
    double rectangle1Y2 =   0.0;

    double rectangle2X1 =   0.0;
    double rectangle2Y1 =   0.0;
    double rectangle2X2 =   0.0;
    double rectangle2Y2 =   0.0;

    puts("Please enter the Coordinates of the first Rectangle: ");
    puts("Mind to enter only 2 opposite points's coordinates starting with the the upperleft one... ");

    if (!(cin >> rectangle1X1 >> rectangle1Y1 >> rectangle1X2 >> rectangle1Y2)) {
        puts("Invalid Input!");

        return 1;

    }

    puts("Please enter the Coordinates of the second Rectangle: ");
    puts("Mind to enter only 2 opposite points's coordinates starting with the the upperleft one... ");

    if (!(cin >> rectangle2X1 >> rectangle2Y1 >> rectangle2X2 >> rectangle2Y2)) {
        puts("Invalid Input!");

        return 1;

    }

    if (rectangle2X2 < rectangle2X1 || rectangle2Y2 < rectangle2Y1) {
        puts("Invalid Coordinates for Rectangle!");

        return 2;
    }

    bool conditionOverlap1 = ((rectangle2X1 < rectangle1X2) && (rectangle2X2 > rectangle1X1));
    bool conditionOverlap2 = ((rectangle2Y1 < rectangle1Y2) && (rectangle2Y2 > rectangle1Y1));

    cout << "Do the rectangles overlap? " << ((conditionOverlap1 && conditionOverlap2) ? "Yes" : "No") << endl;

    return 0;

}