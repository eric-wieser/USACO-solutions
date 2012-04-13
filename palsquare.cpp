/*
ID: wieser.1
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <memory>
using namespace std;

ofstream out("palsquare.out");
ifstream in("palsquare.in");

string chars = "0123456789ABCDEFGHIJ";

string intToBase(int n, int base) {
	string res = "";
	while(n) {
		res = chars[n % base] + res;
		n /= base;
	}
	return res;
}

string reverse(string s) {
	string rev;
	for(int i = 0; i < s.length(); i++)
		rev = s[i] + rev;
	return rev;
}

int main() {
	int base;
	in >> base;

	for(int i = 1; i <= 300; i++) {
		string repr = intToBase(i*i, base);
		if(repr == reverse(repr))
			out << intToBase(i, base) << " " << repr << endl;
	}
}