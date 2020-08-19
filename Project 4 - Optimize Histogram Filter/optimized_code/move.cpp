#include "headers/move.h"
#include "headers/zeros.h"

using namespace std;

vector< vector <float> > move(int dy, int dx, vector < vector <float> > &beliefs)
{
	static int height = beliefs.size();
	static int width = beliefs[0].size();

	static vector < vector <float> > newGrid = zeros(height, width);
	
  	for (static int i=0; i<height; i++) {
		for (static int j=0; j<width; j++) {
			static int new_i = (i + dy + height) % height;
			static int new_j = (j + dx + width)  % width;
			static float belief = beliefs[i][j];

			newGrid[new_i][new_j] = belief;
		}
	}
	return newGrid;
}
