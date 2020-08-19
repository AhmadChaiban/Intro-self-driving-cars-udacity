#include "headers/zeros.h"

using namespace std;

vector < vector <float> > zeros(int height, int width) {
    static vector < vector <float> > newGrid (height, vector<float> (width, 0));

    return newGrid;
}