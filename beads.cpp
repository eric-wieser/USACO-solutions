/*
ID: wieser.1
LANG: C++
PROG: beads
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

ofstream out("beads.out");
ifstream in("beads.in");

template <typename T>
class CircularArray {
	private:
		T* _data;
		size_t _len;
		int _rot;
	public:
		CircularArray(T* data, size_t n) : _data(data), _len(n), _rot(0) { }
		T& operator[](int n) {
			assert(n < _len);
			n += _rot;
			return _data[(n % _len + _len) % _len];
		}
		size_t size() { return _len; }

		void dump(ostream &o) {
			for(int i = 0; i < _len; i++)
				o << (*this)[i];
			o << endl;
		}

		bool rotate() {
			_rot++;
			return _rot % _len != 0;
		}
};

int main() {
	size_t n;
	in >> n;
	in.ignore(1);
	char* s = new char[n];
	in.read(s, n);

	CircularArray<char> necklace(s, n);

	int max = 0;

	do {
		char startBead = 'w';
		int i, j;

		for(i = 0; i < n; i++) {
			char b = necklace[i];
			if(startBead == 'w')
				startBead = b;
			else if(b != startBead && b != 'w') {
				break;
			}
		}

		char endBead = 'w';
		for(j = 1; j < n - i; j++) {
			char b = necklace[n - j];
			if(endBead == 'w')
				endBead = b;
			else if(b != endBead && b != 'w'){
				break;
			}
		}

		//out << i << " " << startBead << "s, " << j << " "  << endBead << "s" << endl;
		//necklace.dump(out);
		int beads = i + j == n ? n : i + j - 1;
		max = beads > max ? beads : max;

	} while(necklace.rotate());

	out << max << endl;
}