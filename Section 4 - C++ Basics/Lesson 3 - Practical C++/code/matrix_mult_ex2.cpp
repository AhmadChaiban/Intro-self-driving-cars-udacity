#include <iostream>
#include <vector>

using namespace std;

vector < vector <float> > create_matrix(vector<float> row, int n_rows);
vector < vector <float> > multiply_matrices (vector < vector <float> > matrix1, vector < vector <float> > matrix2);
vector < vector <float> > transpose_matrix (vector < vector <float> > matrix_to_transpose);
bool print_matrix(vector< vector <float> > vector_to_print);

int main(){

    vector<float> row1(5, 5);
    vector < vector <float> > matrix1 = create_matrix(row1 ,4);

    vector<float> row2(2, 4);
    vector < vector <float> > matrix2 = create_matrix(row2 ,5);

    vector < vector <float> > matrix_mult = multiply_matrices(matrix1, matrix2);

    print_matrix(matrix_mult);

}

vector < vector <float> > multiply_matrices (vector < vector <float> > matrix1, vector < vector <float> > matrix2){
    if(matrix1[0].size() != matrix2.size()){
        throw ("cannot multiply matrices");
    }
    vector < vector <float> > matrix2T = transpose_matrix(matrix2);
    float element;
    vector<float> row_result(matrix2T.size());
    vector < vector <float> > matrix_result;
    for(int i=0; i<matrix1.size(); i++){
        for(int j=0; j<matrix2T.size(); j++){
            element = 0;
            for(int k = 0; k<matrix2T[0].size(); k++){
                element = element + (matrix1[i][k] * matrix2T[j][k]);
            }
            row_result[j] = element;
        }
        matrix_result.push_back(row_result);
    }
    return matrix_result;
}

vector < vector <float> > transpose_matrix (vector < vector <float> > matrix_to_transpose) {
    vector < vector <float> > result_matrix;
    vector<float> row_flipped(matrix_to_transpose.size());
    for (int i = 0; i < matrix_to_transpose[0].size(); i++) {
        for(int j = 0; j< matrix_to_transpose.size(); j++){
            row_flipped[j] = matrix_to_transpose[j][i];
        }
        result_matrix.push_back(row_flipped);
    }
    return result_matrix;
}

vector < vector <float> > create_matrix(vector<float> row, int n_rows){
    vector < vector <float> > matrix_result;
    for(int i =0; i<n_rows;i++){
        matrix_result.push_back(row);
    }
    return matrix_result;
}

bool print_matrix(vector< vector <float> > vector_to_print){
    for(int i=0; i<vector_to_print.size(); i++) {
        for(int j=0; j<vector_to_print[0].size(); j++) {
            cout << vector_to_print[i][j] << " ";
        }
        cout << endl;
    }
    return true;
}



