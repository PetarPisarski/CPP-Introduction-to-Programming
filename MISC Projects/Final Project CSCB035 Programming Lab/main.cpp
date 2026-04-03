#include <iostream>
#include "functions.h"
 
using namespace std;
 
int main() {
 
    unsigned long long maxLimit = 2305843008139952128;
    unsigned long long perfectNumbers[8];
    char formattedStrings[8][100];
 
    savePerfectMersenne(8, perfectNumbers);
    formatPerfectString(8, formattedStrings);
 
    cout << "Perfect numbers list:" << endl;
    for (int i = 0; i < 8; i++) {
 
        cout << i + 1 << ": " << perfectNumbers[i] << " ---> " << formattedStrings[i] << endl;
 
        if (perfectNumbers[i] == maxLimit) {
            cout << "Gotovo!" << endl;
 
        }
    }
 
    return 0;
}