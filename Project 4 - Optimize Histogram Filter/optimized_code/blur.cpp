#include "headers/blur.h"
#include <iostream>

using namespace std;

vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	static int height = grid.size();
	static int width = grid[0].size();

    static vector < vector <float> > newGrid (height, vector<float> (width, 0.0));

    static float center = 1.0 - blurring;
	static float corner = blurring / 12.0;
	static float adjacent = blurring / 6.0;

    static vector < vector <float> > window = {
            {corner, adjacent, corner},
            {adjacent, center, adjacent},
            {corner, adjacent, corner}
    };

    static vector <int> DX = {-1, 0, 1};
    static vector <int> DY = {-1, 0, 1};

	/*Defining static int here for every int in the for loop.
	This greatly reduces the amount of time these nested
	for loops take.*/
	for (static int i=0; i< height; i++ ) {
		for (static int j=0; j<width; j++ ) {
            static float val = grid[i][j];
			for (static int ii=0; ii<3; ii++) {
				static int dy = DY[ii];
				for (static int jj=0; jj<3; jj++) {
					static int dx = DX[jj];
					static int new_i = (i + dy + height) % height;
					static int new_j = (j + dx + width) % width;
					static float multiplier = window[ii][jj];
					newGrid[new_i][new_j] += val * multiplier;
				}
			}
		}
	}

	return newGrid;
}
