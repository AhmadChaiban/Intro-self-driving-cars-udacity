#include <iostream>

bool neg_checker(int digit);
bool vehicle_state(char state);

int main() {
    
    /* 
    * TODO: Use this as a playground for writing if, else if and else statements
    * To get you started here, are some ideas:
    * 
    * 1. Create an integer variable and a set of if, elseif and else statements that
    * output whether the number is positive or negative.
    * 
    * 2. Create a character variable containing 'a' for acceleration, 'b' for braking, 
    * 'p' for parked, or 'n' for neutral and outputs whether or not the vehicle is accelerating, braking, 
    * parked or in neutral.
    *
    * Practice Using Boolean Logic
    *
    * You can see an example solution in the solution.cpp file
    */

    int digit = 1;
    neg_checker(1);

    char state = 'b';
    vehicle_state(state);

    return 0;
}

bool neg_checker(int digit){
    if(digit >= 0){
        std::cout << "positive" << std::endl;
    }
    else{
        std::cout << "negative" << std::endl;
    }
    return true;
}

bool vehicle_state(char state){
    if(state == 'p'){
        std::cout << "parked" << std::endl;
    }
    else if (state == 'n'){
        std::cout << "neutral" << std::endl;
    }
    else if (state == 'a'){
        std::cout << "acceleration" << std::endl;
    }
    else if (state == 'b'){
        std::cout << "braking" << std::endl;
    }
    return true;
}

