#include <iostream>

// Quiz: Write a Function
// Write a function, called distance, with three inputs and one output. The inputs are velocity, acceleration and time. The output is the distance traveled 
// over the elapsed time. The equation for calculating distance is: distance = velocity \times elapsedtime + 0.5 \times acceleration \times elapsedtime \times 
// elapsedtimedistance = velocity * elapsedtime + 0.5 * acceleration * elapsedtime * elapsedtime

// This quiz is not graded. You will see some test cases in the main() function to test out your code. To run your code, click on the "Test Run" button.

// A solution has been provided in the solution.cpp so that you can compare your results.

float distance(float velocity, float elapsed_time, float acceleration);

int main(){
    
    std::cout << distance(3, 4, 5) << std::endl;
    std::cout << distance(7.0, 2.1, 5.4) << std::endl;

    return 0;
}

float distance(float velocity, float elapsed_time, float acceleration){
    return velocity * elapsed_time + 0.5 * acceleration * elapsed_time * elapsed_time;
}

