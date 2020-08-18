#include "reserved.hpp"
using namespace std;

vector< vector<int> > reserved(int rows, int cols, int initial_value) {
    
    vector< vector<int> > matrix;
    matrix.reserve(rows);
    vector<int> new_row;
    new_row.reserve(cols);

    //Depending on the size of the intended vector, it is sometimes a good idea
    //to prepare the memory for the columns of the matrix as well
    for(vector < vector<int> >::iterator it=matrix.begin(); it!=matrix.end(); ++it) {
        it->reserve(cols);
    }
    
    for (int i = 0; i < rows; i++) {
        new_row.clear();
        for (int j = 0; j < cols; j++) {
            new_row.push_back(initial_value);
        }
        matrix.push_back(new_row);
    }
    
    return matrix;
}

