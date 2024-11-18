//pc3656
//10/25/24
//Calendar

#include<iostream>
#include<string>
using namespace std;

//Constants for the Days
const string MO("Mon"), TU("Tue"), WE("Wed"), TH("Thu"), FR("Fri"), SA("Sat"), SU("Sun");
const int JAN(31), FEB(28), FEB_L(29), MAR(31), APR(30), MAY(31), JUN(30), JUL(31), AUG(31), SEP(30), OCT(31), NOV(30), DEC(31); 
const char T('\t');

//Function prototypes.
int printMonthCalender(int numOfDays, int startingDay);
bool isLeap(int year);
void printYearCalender(int year, int startingDay);
int nextDay(int day);


int main() {
    int year;
    int startingDay;
    cout << "Please enter a year: ";
    cin >> year;
    cout << "Please enter the starting day of " << year << " as an integer. e.g. Monday = 1, Tuesday = 2, etc: ";
    cin >> startingDay;
    printYearCalender(year, startingDay);
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    int endDay(startingDay), counterDays(1);
    bool started = false;

    //Print the header.
    cout << MO << T << TU << T << WE << T << TH << T << FR << T << SA << T << SU << T << endl;
    //Print the days
    while(counterDays <= numOfDays) {
        //First line, starting to count at the right day.
        if (startingDay == 1) {
            started = true;
        }
        if (!started) {
            cout << T;
            counterDays ++;
            if (counterDays == startingDay) {
                started = true;
                counterDays = 1;
            }
        }
        else {
            //End of a line.
            if (endDay > 7) {
                cout << endl;
                endDay = 1;
            }
            cout << counterDays << T;
            counterDays ++;
            endDay ++;
        }
    }
    cout << endl;
    return endDay - 1;
}

bool isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 400 == 0) {
            return true;
        }
        else if (year % 100 == 0) {
            return false;
        }
        else return true;
    }
    else return false;
}

int next(int day) {
    if (day == 7) {
        return 1;
    }
    else return day + 1;
}

void printYearCalender(int year, int startingDay) {
    cout << endl << "January " << year << endl;
    int nextDay = next(printMonthCalender(JAN, startingDay));

    cout << endl << "February" << year << endl;
    if (isLeap(year)) {
        nextDay = next(printMonthCalender(FEB_L, nextDay));
    }
    else nextDay = next(printMonthCalender(FEB, nextDay));

    cout << endl << "March " << year << endl;
    nextDay = next(printMonthCalender(MAR, nextDay));

    cout << endl << "April " << year << endl;
    nextDay = next(printMonthCalender(APR, nextDay));

    cout << endl << "May " << year << endl;
    nextDay = next(printMonthCalender(MAY, nextDay));

    cout << endl << "June " << year << endl;
    nextDay = next(printMonthCalender(JUN, nextDay));

    cout << endl << "July " << year << endl;
    nextDay = next(printMonthCalender(JUL, nextDay));

    cout << endl << "August " << year << endl;
    nextDay = next(printMonthCalender(AUG, nextDay));

    cout << endl << "September " << year << endl;
    nextDay = next(printMonthCalender(SEP, nextDay));

    cout << endl << "October " << year << endl;
    nextDay = next(printMonthCalender(OCT, nextDay));

    cout << endl << "November " << year << endl;
    nextDay = next(printMonthCalender(NOV, nextDay));

    cout << endl << "December " << year << endl;
    nextDay = next(printMonthCalender(DEC, nextDay));
}