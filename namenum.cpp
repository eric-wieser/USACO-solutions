/*
ID: wieser.1
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <memory>
using namespace std;

ofstream out("namenum.out");
ifstream in("namenum.in");
ifstream dict("dict.txt");

char *DECODE = "22233344455566670778889990";

char getKeyFor(char c) {
	return DECODE[c - 'A'];
}

string getIdFor(string name) {
	string id = "";
	for(int i = 0; i < name.length(); i++) {
		char key = getKeyFor(name[i]);
		if(key == 0)
			return 0;
		id += key;
	}
	return id;
}

int main() {
	string id;
	in >> id;

	string name;
	bool found = false;

	string test = getIdFor("KRISTOPHER");

	while(dict >> name) {
		string number = getIdFor(name);
		if(number == id) {
			out << name << endl;
			found = true;
		}
	}
	if(!found) out << "NONE" << endl;
}