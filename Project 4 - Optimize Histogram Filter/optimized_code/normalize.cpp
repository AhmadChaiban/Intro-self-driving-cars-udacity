#include "headers/normalize.h"
using namespace std;

vector< vector<float> > normalize(vector< vector <float> > &grid) {

	static float total = 0;
	for (static int i = 0; i < grid.size(); i++){
		for (static int j=0; j< grid[0].size(); j++){
			total += grid[i][j];
		}
	}

	for (static int i = 0; i < grid.size(); i++) {
		for (static int j=0; j< grid[0].size(); j++) {
		    grid[i][j] = grid[i][j] / total;
		}
	}
	return grid;
}
