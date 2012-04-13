/*
ID: wieser.1
LANG: C++
TASK: calfflac
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;

ofstream out("calfflac.out");
ifstream in("calfflac.in");

main() {
	stringstream buffer;
	buffer << in.rdbuf();
	string s = buffer.str();
	string best = "";
	int longest = 1;
	for(string::iterator i = s.begin(); i != s.end(); i++) {
		string::iterator start, end;
		start = end = i;
		int size = isalpha(*i) ? 1 : 0;
		while(true) {
			bool done = false;
			do {
				start--;
				done |= start < s.begin();
			} while(!done && !isalpha(*start));

			do {
				end++;
				done |= end >= s.end();
			} while(!done && !isalpha(*end));

			if(done || tolower(*start) != tolower(*end))
				break;

			size += 2;

			if(size > longest) {
				best = string(start, end+1);
				longest = size;
			}
		}
	}
	out << longest << endl << best << endl;
}