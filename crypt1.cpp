/*
ID: wieser.1
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cctype>
using namespace std;

ofstream out("crypt1.out");
ifstream in("crypt1.in");

bool inSet(int n, set<int> s) {
	while(n > 0) {
		int digit = n % 10;
		n /= 10;
		if(s.find(digit) == s.end())
			return false;
	}
	return true;
}

main() {
	int n;
	set<int> numbers;

	in >> n;

	for(int i = 0; i < n; i++) {
		int x;
		in >> x;
		numbers.insert(x);
	}

	int count = 0;

	typedef set<int>::iterator itr;

	for(itr i = numbers.begin(); i != numbers.end(); i++)
	for(itr j = numbers.begin(); j != numbers.end(); j++)
	for(itr k = numbers.begin(); k != numbers.end(); k++)
	for(itr l = numbers.begin(); l != numbers.end(); l++)
	for(itr m = numbers.begin(); m != numbers.end(); m++) {
		int first = (*i) * 100 + (*j) * 10 + (*k);
		int second = (*l) * 10 + (*m);

		int third = (*m) * first;
		int fourth = (*l) * first;

		int last = first * second;


		if(last < 10000 &&
		   third < 1000 &&
		   fourth < 1000 &&
		   inSet(last, numbers) &&
		   inSet(third, numbers) &&
		   inSet(fourth, numbers)) {
			count++;
		}

	}

	out << count << endl;
}