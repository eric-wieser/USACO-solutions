/*
ID: wieser.1
LANG: C++
PROG: gift1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ofstream out("gift1.out");
ifstream in("gift1.in");

class Person {
public:
	static vector<Person*> people;
	string name;
	vector<Person*> giveTo;
	int gives;
	int recieves;

	Person(string name) : name(name), gives(0), recieves(0) { }

	void sendGifts() {
		int n = giveTo.size();
		if(n > 0) {
			int giveEach = gives / n;
			for(int i = 0; i < n; i++)
				giveTo[i]->recieves += giveEach;

			this->gives = giveEach * n;
		}
	}

	void dump(ofstream &f) {
		f << this->name << endl;
		f << "\trecieving:" << this->recieves << endl;
		f << "\tgiving:" << this->gives << endl;
		f << "\tto:" << endl;
		for(int i = 0; i < this->giveTo.size(); i++)
			f << "\t\t" << this->giveTo[i]->name << endl;
	}

	static Person* byName(string name) {
		for(int i = 0; i < people.size(); i++)
			if(people[i]->name == name)
				return people[i];
	}
};
vector<Person*> Person::people;


int main () {

	int n;
	in >> n;

	for(int i = 0; i < n; i++) {
		string name;
		in >> name;
		Person* p = new Person(name);
		Person::people.push_back(p);
	}
	for(int i = 0; i < n; i++) {
		string giverName;
		in >> giverName;
		Person* giver = Person::byName(giverName);
		in >> giver->gives;
		int ng;
		in >> ng;
		for(int j = 0; j < ng; j++) {
			string recipientName;
			in >> recipientName;
			Person* recipient = Person::byName(recipientName);
			giver->giveTo.push_back(recipient);
		}
	}
	for(int i = 0; i < n; i++) {
		Person::people[i]->sendGifts();
	}
	for(int i = 0; i < n; i++) {
		Person* p = Person::people[i];
		out << p->name << " " << p->recieves - p->gives << endl;
	}
}