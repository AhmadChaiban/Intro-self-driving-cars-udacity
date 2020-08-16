#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
// #include "debugging_helpers.cpp"

using namespace std;

float calculate_total(vector< vector <float> > grid){
    //Function for calculating the total sum of the probability grid
    float total = 0.0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            total = total + grid[i][j];
        }
    }
    return total;
}

vector< vector<float> > normalize(vector< vector <float> > grid) {

        /*Given a grid of un-normalized probabilities, computes the
        correspond normalized version of that grid.*/

        float total = calculate_total(grid);

	    for(int i=0; i<grid.size(); i++){
	        for(int j=0; j<grid.size(); j++){
	            grid[i][j] = grid[i][j]/total;
	        }
	    }
	    return grid;
}

vector < vector <float> > initialize_grid(vector<float>::size_type rows,
                                          vector<float>::size_type columns){
    //Creating the initial grid with 0s
    vector < vector <float> > initial_grid(rows, vector<float> (columns, 0));
    return initial_grid;
}

vector < vector <float> > create_window(float center_prob, float corner_prob, float adjacent_prob){
    /*Creating a 3x3 blur window*/
    vector < vector <float> > window;
    vector<float> single_row;

    single_row.push_back(corner_prob);
    single_row.push_back(adjacent_prob);
    single_row.push_back(corner_prob);
    window.push_back(single_row);
    single_row.clear();

    single_row.push_back(adjacent_prob);
    single_row.push_back(center_prob);
    single_row.push_back(adjacent_prob);

    window.push_back(single_row);
    single_row.clear();

    single_row.push_back(corner_prob);
    single_row.push_back(adjacent_prob);
    single_row.push_back(corner_prob);

    window.push_back(single_row);
    single_row.clear();

    return window;
}



vector < vector <float> > blur(vector < vector < float> > grid, float blurring) {

    /*Spreads probability out on a grid using a 3x3 blurring window.
    The blurring parameter controls how much of a belief spills out
    into adjacent cells. If blurring is 0 this function will have
    no effect.*/

	vector<float>::size_type height = grid.size();
	vector<float>::size_type width = grid[0].size();

    vector < vector <float> > newGrid = initialize_grid(height, width);

    float center_prob = 1.0 - blurring;
    float corner_prob = blurring/12.0;
    float adjacent_prob = blurring/6.0;

    vector< vector<float> > window = create_window(center_prob, corner_prob, adjacent_prob);

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            for(int dx=-1; dx< 2; dx++){
                for(int dy=-1; dy<2; dy++){
                    int new_i = (i + dy) % height;
                    int new_j = (j + dx) % width;
                    newGrid[new_i][new_j] += window[dx+1][dy+1] * grid[i][j];
                }
            }
        }
    }
	return normalize(newGrid);
}

/** -----------------------------------------------
#
#
#	You do not need to modify any code below here.
#
#
# ------------------------------------------------- */


/**
    Determines when two grids of floating point numbers 
    are "close enough" that they should be considered 
    equal. Useful for battling "floating point errors".

    @param g1 - a grid of floats
    
    @param g2 - a grid of floats

    @return - A boolean (True or False) indicating whether
    these grids are (True) or are not (False) equal.
*/
bool close_enough(vector < vector <float> > g1, vector < vector <float> > g2) {
	int i, j;
	float v1, v2;
	if (g1.size() != g2.size()) {
		return false;
	}

	if (g1[0].size() != g2[0].size()) {
		return false;
	}
	for (i=0; i<g1.size(); i++) {
		for (j=0; j<g1[0].size(); j++) {
			v1 = g1[i][j];
			v2 = g2[i][j];
			if (abs(v2-v1) > 0.0001 ) {
				return false;
			}
		}
	}
	return true;
}

bool close_enough(float v1, float v2) { 
	if (abs(v2-v1) > 0.0001 ) {
		return false;
	} 
	return true;
}

/**
    Helper function for reading in map data

    @param s - a string representing one line of map data.

    @return - A row of chars, each of which represents the
    color of a cell in a grid world.
*/
vector <char> read_line(string s) {
	vector <char> row;

	size_t pos = 0;
	string token;
	string delimiter = " ";
	char cell;

	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());

		cell = token.at(0);
		row.push_back(cell);
	}

	return row;
}

/**
    Helper function for reading in map data

    @param file_name - The filename where the map is stored.

    @return - A grid of chars representing a map.
*/
vector < vector <char> > read_map(string file_name) {
	ifstream infile(file_name);
	vector < vector <char> > map;
	if (infile.is_open()) {

		char color;
		vector <char> row;
		
		string line;

		while (std::getline(infile, line)) {
			row = read_line(line);
			map.push_back(row);
		}
	}
	return map;
}

/**
    Creates a grid of zeros

    For example:

    zeros(2, 3) would return

    0.0  0.0  0.0
    0.0  0.0  0.0

    @param height - the height of the desired grid

    @param width - the width of the desired grid.

    @return a grid of zeros (floats)
*/
vector < vector <float> > zeros(int height, int width) {
	int i, j;
	vector < vector <float> > newGrid;
	vector <float> newRow;

	for (i=0; i<height; i++) {
		newRow.clear();
		for (j=0; j<width; j++) {
			newRow.push_back(0.0);
		}
		newGrid.push_back(newRow);
	}
	return newGrid;
}

// int main() {
// 	vector < vector < char > > map = read_map("maps/m1.txt");
// 	show_grid(map);
// 	return 0;
// }
