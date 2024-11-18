//pc3656
//10/29/24

#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int n(0), countDivs, sumDivs;
    while (n < 2) {
        cout << "Enter a number greater than or equal to 2: ";
        cin >> n;
    }
    //Iterate over the number
    for (int i = 2; i <=n; i++) {
        if(isPerfect(i)) {
            cout << i << " is a perfect number." << endl;
            continue;
        }
        analyzeDividors(i, countDivs, sumDivs);
        int tmpSum = sumDivs;
        analyzeDividors(sumDivs, countDivs, sumDivs);
        if ((i == sumDivs) && (i != tmpSum) && (tmpSum <= n)) {
            cout << i << " and " << tmpSum << " are amicable numbers." << endl;
        }

    }
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    //Initialize those two variables. 
    //I already count 1 as a first divisor and as the start of the sum 
    outCountDivs = 1;
    outSumDivs = 1;
    int sumDivs(1);
    //Starting at 2
    for(int i = 2; i <= sqrt(num); i++) {
        if ((num % i) == 0) {
            outCountDivs ++;
            outSumDivs += i;
            if (i != (num / i)) {
                outCountDivs ++;
                outSumDivs += num / i;
            }
        }
    }
}

bool isPerfect(int num) {
    int checkCount, checkSum;
    analyzeDividors(num, checkCount, checkSum);
    if(num == checkSum) {
        return true;
    }
    else return false;
}
