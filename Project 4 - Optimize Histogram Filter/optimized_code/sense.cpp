#include "headers/sense.h"

using namespace std;

vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss)
{
	for (static int i=0; i<grid.size(); i++) {
		for (static int j=0; j<grid[0].size(); j++) {
			if (grid[i][j] == color) {
				beliefs[i][j] = beliefs[i][j] * p_hit;
			}
			else{
			    beliefs[i][j] = beliefs[i][j] * p_miss;
			}
		}
	}
	return beliefs;
}
