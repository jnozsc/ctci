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

bool isRotation(string s1, string s2);
bool isSubstring(string s1, string s2);

int main(int argc, const char* argv[]) {

    // insert code here...
    string s1 = "aa";
    string s2 = "aab";
    cout << boolalpha  << isSubstring(s2, s1) << endl; // true
    cout << boolalpha  << isSubstring(s1, s2) << endl; // false
    string s3 = "apple";
    string s4 = "pleap";
    string s5 = "pleab";
    cout << boolalpha << isRotation(s3, s4) << endl; // true;
    cout << boolalpha << isRotation(s3, s5) << endl; // false;
    return 0;
}


bool isSubstring(string s1, string s2) {
    return s1.find(s2, 0) != -1;
}

bool isRotation(string s1, string s2) {
    if (!s1.empty() && !s2.empty() && s1.length() == s2.length()) {
        string s1s1 = s1 + s1;
        return isSubstring(s1s1, s2);
    }
    return false;
}