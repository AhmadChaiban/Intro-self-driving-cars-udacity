#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<float> sense(vector<float> p, string Z, float pHit, float pMiss, vector<string> world);
vector<float> move(vector<float> p, int U, float pExact, float pOvershoot, float pUndershoot);
bool print_vector(vector <float> vector_to_print);
bool print_vector(vector <string> vector_to_print);

int main(){
    vector<float> p(5, 0.2);

    vector<string> world (5);
    world[0] = world[3] = world[4] = "green";
    world[1] = world[2] = "red";

    vector<string> measurements (2);
    measurements[0] = "red";
    measurements[1] = "green";

    vector<int> motions (2, 1);

    float pHit = 0.6;
    float pMiss = 0.2;
    float pExact = 0.8;
    float pOvershoot = 0.1;
    float pUndershoot = 0.1;

    for(int k=0; k<measurements.size(); k++){
        p = sense(p, measurements[k], pHit, pMiss, world);
        p = move(p, motions[k], pExact, pOvershoot, pUndershoot);
    }

    print_vector(p);

}

vector<float> sense(vector<float> p, string Z, float pHit, float pMiss, vector<string> world){
    vector<float> q;
    float sum_q = 0;
    for(int i = 0; i<p.size(); i++){
        if(Z == world[i]){
            q.push_back(p[i]*pHit);
        }
        else{
            q.push_back(p[i]*pMiss);
        }
        sum_q = sum_q + q[i];
    }
    for(int j = 0; j<q.size(); j++){
        q[j] = q[j]/sum_q;
    }
    return q;
}

vector<float> move(vector<float> p, int U, float pExact, float pOvershoot, float pUndershoot){
    vector<float> q;
    float s = 0;
    // The modulo operator behaves a bit different in C++ with negatives
    // If we took it as -1 % p.size(), we'd get zero instead of four
    // -1 + p.size() will give us what we would get from -1 % p.size in Python
    for(int i = 0; i<p.size(); i++){
        if (i-U < 0) {
            s = pExact * p[(i-U) + p.size()];
        }
        else {
            s = pExact * p[(i-U) % p.size()];
        }
        if (i-U-1 < 0) {
            s = s + pOvershoot * p[(i-U-1) + p.size()];
        }
        else {
            s = s + pOvershoot * p[(i-U-1) % p.size()];
        }
        if (i-U+1 < 0) {
            s = s + pUndershoot * p[(i-U+1) + p.size()];
        }
        else {
            s = s + pUndershoot * p[(i-U+1) % p.size()];
        }
        q.push_back(s);
    }
    return q;
}

bool print_vector(vector <float> vector_to_print){
    for(int i=0; i<vector_to_print.size(); i++) {
        cout << vector_to_print[i] << " ";
    }
    cout << endl;
    return true;
}

bool print_vector(vector <string> vector_to_print){
    for(int i=0; i<vector_to_print.size(); i++) {
        cout << vector_to_print[i] << " ";
    }
    cout << endl;
    return true;
}