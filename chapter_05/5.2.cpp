//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

string printBinary(double num);

int main(int argc, const char* argv[]) {
    // insert code here...
    double a = (double)rand() / RAND_MAX;
    double b = (double)rand() / RAND_MAX;
    double c = 0.625;
    cout << a << " can be printed as " << printBinary(a) << endl;
    cout << b << " can be printed as " << printBinary(b) << endl;
    cout << c << " can be printed as " << printBinary(c) << endl;
    return 0;
}

string printBinary(double num) {
    if (num > 1 || num < 0) {
        return "ERROR";
    }
    string result = "";
    double frac = 0.5;
    result = result + ".";
    while (num > 0) {
        if (result.length() > 32) return "ERROR";
        if (num >= frac) {
            result = result + "1";
            num -= frac;
        } else {
            result = result + "0";
        }
        frac /= 2;
    }
    return result;
}