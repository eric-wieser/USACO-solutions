/*
ID: wieser.1
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <memory>
using namespace std;

ofstream out("dualpal.out");
ifstream in("dualpal.in");

string chars = "0123456789";

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
	int n, start;
	in >> n >> start;
	int found = 0;
	for(int i = start + 1; found < n; i++) {
		int palindromeCount = 0;
		for(int base = 2; base <= 10; base++) {
			string repr = intToBase(i, base);
			if(repr == reverse(repr))
				palindromeCount++;
			if(palindromeCount >= 2) {
				out << i << endl;
				found++;
				break;
			}
		}
	}
}