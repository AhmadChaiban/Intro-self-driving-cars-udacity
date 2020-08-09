#include <iostream>

int main() {
    
    // TODO: define two floating point numbers. Assign 12.07 to the
    // first floating point number. Assign 65.102 to the 
    // second floating point number.
    
    
    // TODO: Calculate the sum of the two floating point variables into
    // the float_sum variable.
    
    float x1 = 12.07;
    float x2 = 65.102; 

    float float_sum = x1+x2;
    
    std::cout << float_sum << std::endl;
    
    // TODO: Calculate difference between the second and first number
    // output the results to cout. 

    float float_diff = x2-x1;
    
    std::cout << float_diff << std::endl;
    
    // TODO: Calculate second_float / first_float and output the results
    // to cout.

    float float_div = x2/x1;
    
    std::cout << float_div << std::endl;
    
    // TODO: Calculate the product of the two numbers and output the results
    // to cout.

    float flat_prod = x1*x2;
    
    std::cout << flat_prod << std::endl;

    return 0;
}