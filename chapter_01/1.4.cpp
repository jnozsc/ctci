//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

string replaceAllSpace(string s);

int main(int argc, const char* argv[]) {

    // insert code here...
    string s1 = "a B c";
    string s2 = " A b C ";
    cout << s1 << endl;
    cout << replaceAllSpace(s1) << endl;
    cout << s2 << endl;
    cout << replaceAllSpace(s2) << endl;
    return 0;
}

string replaceAllSpace(string s) {
    if (s.empty()) {
        return "";
    }
    string result = s;
    while (result[0] == ' ') {
        result = result.substr(1);
    }
    while (result[result.length() - 1] == ' ') {
        result = result.substr(0, result.length() - 1);
    }
    for (size_t pos = result.find(' '); pos != string::npos; pos = result.find(' ', pos)) {
        result.replace(pos, 1, "%20");
    }
    return result;
}