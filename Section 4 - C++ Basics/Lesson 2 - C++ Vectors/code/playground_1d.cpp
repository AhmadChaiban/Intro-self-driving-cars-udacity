#include <iostream>
#include <vector>

using namespace std;

vector<float> v_sub_mult(vector<float> vector1, vector<float> vector2, char operation);
bool print_vector(vector<float> vector_to_print);

int main(){

    vector<float> vector1(3);
    vector1[0] = 5;
    vector1[1] = 10;
    vector1[2] = 27;

    vector<float> vector2(3);
    vector2[0] = 3;
    vector2[1] = 17;
    vector2[2] = 12;

    print_vector(v_sub_mult(vector1, vector2, '-'));

    vector<float> vector3(5);
    vector3[0] = 17;
    vector3[1] = 10;
    vector3[2] = 31;
    vector3[2] = 5;
    vector3[2] = 7;

    vector<float> vector4(5);
    vector4[0] = 3;
    vector4[1] = 1;
    vector4[2] = 6;
    vector4[2] = 19;
    vector4[2] = 8;

    print_vector(v_sub_mult(vector3, vector4, '*'));

    return 0;
}

vector<float> v_sub_mult(vector<float> vector1, vector<float> vector2, char operation){
    // Performs vector1 - vector2 but throws an error if they're of different sizes

    if (vector1.size() != vector2.size()){
        throw invalid_argument("Vectors are not the same size");
    }

    vector<float> vector_result (vector1.size());

    for(int i=0; i<vector1.size(); i++){
        if(operation == '-'){
            vector_result[i] = vector1[i] - vector2[i];
        }
        else if(operation == '*'){
            vector_result[i] = vector1[i] * vector2[i];
        }
    }
    return vector_result;
}

bool print_vector(vector<float> vector_to_print){
    for(int i=0; i<vector_to_print.size(); i++){
        cout << vector_to_print[i] << ' ';
    }
    cout << endl;
    return true;
}