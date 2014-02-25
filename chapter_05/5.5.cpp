//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

int bitSwapRequired(int a, int b);

int main(int argc, const char* argv[]) {
    // insert code here...
    int a = 0b11101;
    int b = 0b01111;
    cout << bitSwapRequired(a, b) << endl;
    return 0;
}

int bitSwapRequired(int a, int b) {
    int count = 0;
    for (int c = a ^ b; c != 0; c = c & (c - 1)) {
        count++;
    }
    return count;
}