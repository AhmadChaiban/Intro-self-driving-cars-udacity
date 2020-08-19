#include "headers/initialize_beliefs.h"

using namespace std;

vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {

	static int height = grid.size();
	static int width = grid[0].size();

  	static float prob_per_cell = 1.0 / ( (float) height * width);

    static vector< vector <float> > newGrid (height, vector<float> (width, prob_per_cell));

	return newGrid;
}