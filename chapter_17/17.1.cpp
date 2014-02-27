//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

void swap(int& a, int& b);

int main(int argc, const char* argv[]) {
    // insert code here...
    int a = 3;
    int b = -5;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "swapping ...." << endl;
    swap(a, b);
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    return 0;
}

void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}