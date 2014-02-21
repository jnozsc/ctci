//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix);

int main(int argc, const char* argv[]) {

    // insert code here...
    vector<vector<int>> A;
    int i, j;
    A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    for (i = 0; i < A.size(); i++) {
        for (j = 0; j < A[0].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===rotate===" << endl;
    rotate(A);
    for (i = 0; i < A.size(); i++) {
        for (j = 0; j < A[0].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


void rotate(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}