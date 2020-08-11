#include <iostream>
#include <vector>

using namespace std;

vector< vector <float> > generate_matrix(vector<float> row, int number_columns);
vector< vector <float> > sum_matrices(vector< vector <float> > matrix1, vector< vector <float> > matrix2);
bool print_vector(vector< vector <float> > vector_to_print);

int main(){

    vector<float> rowGeneric1(3, 2.0);
    vector<float> rowGeneric2(3, 5.0);

    vector< vector <float> > matrix_generic1 = generate_matrix(rowGeneric1, 5);
    vector< vector <float> > matrix_generic2 = generate_matrix(rowGeneric2, 5);


    vector< vector <float> > matrix_sum = sum_matrices(matrix_generic1, matrix_generic2);

    print_vector(matrix_sum);

    return 0;

}

vector< vector <float> > generate_matrix(vector<float> row, int number_rows){
    vector< vector <float> > matrix_result;
    for(int i=0; i<number_rows; i++) {
        matrix_result.push_back(row);
    }
    return matrix_result;
}

vector< vector <float> > sum_matrices(vector< vector <float> > matrix1, vector< vector <float> > matrix2){
    if(matrix1.size() != matrix2.size() && matrix1[0].size() != matrix2[0].size()){
        throw invalid_argument("Not the same size");
    }
    vector< vector <float> > matrix_sum;
    vector <float> row_sum(matrix1[0].size());
    for(int i=0; i<matrix1.size(); i++) {
        for(int j=0; j<matrix1[0].size(); j++) {
            row_sum[j] = matrix1[i][j] + matrix2[i][j];
        }
        matrix_sum.push_back(row_sum);
    }
    return matrix_sum;
}

bool print_vector(vector< vector <float> > vector_to_print){
    for(int i=0; i<vector_to_print.size(); i++) {
        for(int j=0; j<vector_to_print[0].size(); j++) {
            cout << vector_to_print[i][j] << " ";
        }
        cout << endl;
    }
    return true;
}