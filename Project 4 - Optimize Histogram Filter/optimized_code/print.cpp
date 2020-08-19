#include "headers/print.h"
#include <iostream>
using namespace std;

void print_vector_float(vector< vector <float> > &grid) {
	static int rows = grid.size();
	static int cols = grid[0].size();

	for (static int i = 0; i < rows; i++) {
		for (static int j = 0; j < cols; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_vector_char(vector< vector <char> > &grid) {
	static int rows = grid.size();
	static int cols = grid[0].size();

	for (static int i = 0; i < rows; i++) {
		for (static int j = 0; j < cols; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}