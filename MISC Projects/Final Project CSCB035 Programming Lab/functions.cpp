#include <iostream>
#include <cstdio>
#include <cmath>
#include "functions.h"
 
using namespace std;
 
// 1. Smqtame sumata na delitelite
unsigned long long sumDivisors(unsigned long long number) {
    unsigned long long sum = 0;
    for (unsigned long long i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum = sum + i;
 
        }
    }
    return sum;
}
 
// 2. Printirame gi na ekrana
void showDivisors(unsigned long long number) {
    for (unsigned long long i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            cout << i << " ";
 
        }
    }
    cout << endl;
}
 
// 3. Tursim obshtite deliteli
int intersectDivisors(unsigned long long number1, unsigned long long number2, unsigned long long* resultArray) {
    int countFound = 0;
    unsigned long long limit = (number1 < number2) ? number1 / 2 : number2 / 2;
    for (unsigned long long i = 1; i <= limit; i++) {
        if (number1 % i == 0 && number2 % i == 0) {
            resultArray[countFound] = i;
            countFound++;
 
        }
    }
    return countFound;
}
 
// Pomoshtna rekursiq za prosti chisla
bool checkPrimeRecursive(unsigned long long number, unsigned long long divisor) {
    if (number < 2) { return false; }
    if (divisor * divisor > number) { return true; }
    if (number % divisor == 0) { return false; }
    return checkPrimeRecursive(number, divisor + 1);
}
 
// 4. Obedinenie na prostite deliteli
int unionPrimeDivisors(unsigned long long number1, unsigned long long number2, unsigned long long* resultArray) {
    int countFound = 0;
    unsigned long long maxVal = (number1 > number2) ? number1 : number2;
    for (unsigned long long i = 2; i <= maxVal; i++) {
        if (checkPrimeRecursive(i, 2)) {
            if (number1 % i == 0 || number2 % i == 0) {
                resultArray[countFound] = i;
                countFound++;
 
            }
        }
    }
    return countFound;
}
 
// 5. Proverka za suvursheno chislo
bool isPerfect(unsigned long long number) {
    if (number < 6) {
        return false;
 
    }
    if (sumDivisors(number) == number) {
        return true;
 
    }
    return false;
}
// 6. Proverka na range
 
void perfectInRange(unsigned long long startRange, unsigned long long endRange) {
    for (unsigned long long i = startRange; i <= endRange; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
 
        }
    }
    cout << endl;
}
 
//7. Pokaji purvite N chisla
 
void showFirstNPerfect(int countN) {
    int foundCount = 0;
    unsigned long long currentNumber = 1;
    while (foundCount < countN) {
        if (isPerfect(currentNumber)) {
            cout << currentNumber << " ";
            foundCount++;
 
        }
        currentNumber++;
    }
    cout << endl;
}
 
//8.  Zapzvame v masiv range
 
int savePerfectRange(unsigned long long startRange, unsigned long long endRange, unsigned long long* resultArray) {
    int countFound = 0;
    for (unsigned long long i = startRange; i <= endRange; i++) {
        if (isPerfect(i)) {
            resultArray[countFound] = i;
            countFound++;
 
        }
    }
    return countFound;
}
 
 
// 9. Purvite 8 suvursheni chrez Mersen
void savePerfectMersenne(int countN, unsigned long long* resultArray) {
    int mersenneP[] = {2, 3, 5, 7, 13, 17, 19, 31};
    for (int i = 0; i < countN && i < 8; i++) {
        int p = mersenneP[i];
        unsigned long long powerPart = ((unsigned long long)1 << p) - 1;
        resultArray[i] = ((unsigned long long)1 << (p - 1)) * powerPart;
 
    }
}
 
// 10. Pravim stringa
void formatPerfectString(int countN, char resultArray[][100]) {
    int mersenneP[] = {2, 3, 5, 7, 13, 17, 19, 31};
    for (int i = 0; i < countN && i < 8; i++) {
        sprintf(resultArray[i], "2^(%d-1).(2^%d-1)", mersenneP[i], mersenneP[i]);
 
    }
}