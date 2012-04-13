/*
ID: wieser.1
LANG: C++
TASK: transform
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <cassert>
#include <memory>
using namespace std;

ofstream out("transform.out");
ifstream in("transform.in");

struct Grid {
	int size;
	shared_ptr<char> data;

	Grid(int n) : size(n) {
		data = shared_ptr<char>(new char[n * n]);
	}

	const char& operator()(int x, int y) const {
		return (data.get())[x + y * size];
	}
	char& operator()(int x, int y) {
		return (*data)[x + y * size];
	}

	friend istream& operator>>(istream& is, Grid& grid)	{
		for(int y = 0; y < grid.size; y++) {
			for(int x = 0; x < grid.size; x++) {
				is >> grid(x, y);
			}
		}

		return is;
	}

	friend ostream& operator<<(ostream& os, Grid& grid)	{
		for(int y = 0; y < grid.size; y++) {
			for(int x = 0; x < grid.size; x++) {
				os << grid(x, y);
			}
			os << endl;
		}
		return os;
	}

	friend bool operator==(const Grid& a, const Grid& b) {
		int s = a.size;
		if(s != b.size) return false;
		for(int y = 0; y < s; y++) {
			for(int x = 0; x < s; x++) {
				if(b(x, y) != a(x, y)) return false;
			}
		}
		return true;
	}
};

Grid rotate90(Grid& g) {
	int n = g.size;
	Grid rotated(n);

	for(int x = 0; x < n; x++)
		for(int y = 0; y < n; y++) {
			rotated(x, y) = g(n - y - 1, x);
		}
	return rotated;
}
Grid rotate180(Grid& g) {
	int n = g.size;
	Grid rotated(n);

	for(int x = 0; x < n; x++)
		for(int y = 0; y < n; y++)
			rotated(x, y) = g(n - x - 1, n - y - 1);
	return rotated;
}
Grid rotate270(Grid& g) {
	int n = g.size;
	Grid rotated(n);

	for(int x = 0; x < n; x++)
		for(int y = 0; y < n; y++)
			rotated(x, y) = g(y, n - x - 1);
	return rotated;
}

Grid reflect(Grid& g) {
	int n = g.size;
	Grid flipped(n);

	for(int x = 0; x < n; x++)
		for(int y = 0; y < n; y++)
			flipped(x, y) = g(n - x - 1, y);
	return flipped;
}

int main() {
	int n;
	in >> n;

	Grid before(n), after(n);

	in >> before;
	in >> after;

	if(rotate90(before) == after)
	    out << 1;
	else if(rotate180(before) == after)
		out << 2;
	else if(rotate270(before) == after)
		out << 3;
	else if(before == after)
		out << 6;
	else {
		Grid reflected = reflect(before);
		if(reflected == after)
			out << 4;
		else if(rotate90(reflected) == after || rotate180(reflected) == after || rotate270(reflected) == after)
			out << 5;
		else
			out << 7;
	}

	out << endl;
}