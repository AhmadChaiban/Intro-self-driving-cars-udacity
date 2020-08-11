#include <iostream>
#include <vector>

using namespace std;

bool print_vector(vector<float> vector_to_print);

int main() {
    
    // Part 1: declare and define a vector with values
    //        {5.0, 5.0, 5.0} and print 
    //         the vector to the terminal using cout
    // Hint: the syntax vector<datatype> varname(length, value) might help

    vector<float> vector1(3, 5.0);
    
    print_vector(vector1);

    // Part 2: Use push back to add the values 3.0, 2.5, 1.4 
    //      to the back of the vector

    vector1.push_back(3.0);
    vector1.push_back(2.5);
    vector1.push_back(1.4);

    // Part 3: Print out the vector again using cout

    print_vector(vector1);

    // Part 4: Use the vector assign method to override the current vector. 
    // The overriden vector should have 3 elements with 
    // the values {5.0, 5.0, 5.0}

    vector1.assign(3, 5.0);

    // Part 5: Print out the vector

    print_vector(vector1);


    return 0;
}

bool print_vector(vector<float> vector_to_print){
    for(int i=0; i<vector_to_print.size(); i++){
        cout << vector_to_print[i] << ", ";
    }
    cout << endl;
    return true;
}