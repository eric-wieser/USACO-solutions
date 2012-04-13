/*
ID: wieser.1
LANG: C++
PROG: ride
*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int score(string s) {
	int n = 1;
	for(int i = 0; i < s.length(); i++)
		n *= s[i] - 'A' + 1;
	return n % 47;
}

int main () {
	ofstream out("ride.out");
	ifstream in("ride.in");

    string comet;
    string group;

    in >> comet;
    in >> group;

    out << (score(comet) == score(group) ? "GO" : "STAY") << endl;
}