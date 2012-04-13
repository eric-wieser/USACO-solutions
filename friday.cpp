/*
ID: wieser.1
LANG: C++
PROG: friday
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ofstream out("friday.out");
ifstream in("friday.in");

enum Day {MON, TUE, WED, THU, FRI, SAT, SUN};
enum Month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

bool isLeapYear(int year) {
	return !(year % 400) || !(year % 4) && (year % 100);
}

int monthLength(int month, int year) {
	if(month == SEP || month == APR || month == SEP || month == JUN || month == NOV)
		return 30;
	else if(month == FEB)
		return isLeapYear(year) ? 29 : 28;
	else
		return 31;
}

int main() {
	int count[] = {0, 0, 0, 0, 0, 0, 0};

	int startYear = 1900;
	int endYear;
	in >> endYear;
	endYear += startYear;

	int daysPassed = 0;
	for(int year = startYear; year < endYear; year++) {
		for(int month = JAN; month <= DEC; month++) {
			count[(daysPassed+12)%7]++;
			daysPassed += monthLength(month, year);
		}
	}

	out << count[SAT] << " "
	    << count[SUN] << " "
	    << count[MON] << " "
	    << count[TUE] << " "
	    << count[WED] << " "
	    << count[THU] << " "
	    << count[FRI] << endl;
}