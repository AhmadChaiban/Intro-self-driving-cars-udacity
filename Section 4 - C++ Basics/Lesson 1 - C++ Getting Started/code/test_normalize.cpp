bool test_normalize() {
    //declare several variables on one line
    vector < vector <float> > unnormalized, normalized, result; 

    unnormalized = zeros(2, 2);
    normalized = zeros(2,2);

    int i,j;

    for (i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            unnormalized[i][j] = 1.0;
            normalized[i][j] = 0.25;
        }
    }

    result = normalize(unnormalized);

    bool correct;
    correct = close_enough(normalized, result);

    if (correct) {
        cout << "! - normalize function worked correctly!\n";
    }
    else {
        cout << "X - normalize function did not work correctly.\n";
        cout << "For the following input:\n\n";
        show_grid(unnormalized);
        cout << "\nYour code returned the following:\n\n";
        show_grid(result);
        cout << "\nWhen it should have returned the following:\n";
        show_grid(normalized);
    }
    return correct;
}