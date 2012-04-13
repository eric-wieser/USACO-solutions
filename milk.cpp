/*
ID: wieser.1
LANG: C++
TASK: milk
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <memory>
using namespace std;

ofstream out("milk.out");
ifstream in("milk.in");

int main() {
	map<long, long> costs;
	map<long, long>::iterator it;

	long n = costs.max_size();

	long target, farmers;
	in >> target >> farmers;

	for(int i = 0; i < farmers; i++) {
		long cost, amount;
		in >> cost >> amount;
		costs[cost] += amount;
		cout << i << costs.size() << endl;
	}

	long cost = 0;
	for(it = costs.begin(); it != costs.end(); it++) {
		if(it->second >= target) {
			cost += it->first * target;
			target = 0;
			break;
		} else {
			target -= it->second;
			cost += it->first * it->second;
		}
	}
	out << cost << endl;
}