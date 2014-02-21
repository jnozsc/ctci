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

void setZeros(vector<vector<int>>& matrix);

int main(int argc, const char* argv[]) {

    // insert code here...
    vector<vector<int>> A;
    int i, j;
    A = {{1, 2, 0, 4}, {5, 6, 7, 8}, {9, 0, 11, 12}, {13, 14, 15, 16}};
    for (i = 0; i < A.size(); i++) {
        for (j = 0; j < A[0].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===setZeros===" << endl;
    setZeros(A);
    for (i = 0; i < A.size(); i++) {
        for (j = 0; j < A[0].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


void setZeros(vector<vector<int>>& matrix) {
    vector<bool> row(matrix.size(), false);
    vector<bool> column(matrix.size(), false);
    int i, j;
    for (i = 0; i < matrix.size(); i++) {
        for (j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    for (i = 0; i < matrix.size(); i++) {
        for (j = 0; j < matrix[0].size(); j++) {
            if (row[i] || column[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}