#ifndef FUNCTIONS_H
#define FUNCTIONS_H
 
// 1. Sumata na delitelite bez samoto chislo
unsigned long long sumDivisors(unsigned long long number);
 
// 2. Pokazva vsichki deliteli bez samoto chislo
void showDivisors(unsigned long long number);
 
// 3. Sechenie na delitelite na dve chisla v masiv
int intersectDivisors(unsigned long long number1, unsigned long long number2, unsigned long long* resultArray);
 
// 4. Obedinenie na prosti deliteli v masiv
int unionPrimeDivisors(unsigned long long number1, unsigned long long number2, unsigned long long* resultArray);
 
// 5. Dali chisloto e suvursheno
bool isPerfect(unsigned long long number);
 
// 6. Pokazva suvurshenite v interval
void perfectInRange(unsigned long long startRange, unsigned long long endRange);
 
// 7. Pokaji purvite N perfektni chisla
void showFirstNPerfect(int countN);
 
// 8. Zapazva v masiv suvurshenite ot interval
int savePerfectRange(unsigned long long startRange, unsigned long long endRange, unsigned long long* resultArray);
 
// 9. Zapazva purvite n chrez Mersen (za osmoto chislo)
void savePerfectMersenne(int countN, unsigned long long* resultArray);
 
// 10. Stringov format 2^(p-1).(2^p-1)
void formatPerfectString(int countN, char resultArray[][100]);
 
#endif