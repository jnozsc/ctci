//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPermutation(string s1, string s2);

int main(int argc, const char* argv[]) {

    // insert code here...
    string s1 = "abc";
    string s2 = "cab";
    string s3 = "";
    // string s4 = NULL; std::string is not a pointer type; it cannot be made "null."
    string s5 = "abcc";
    string s6 = "abb";
    cout << isPermutation(s1, s2) << endl; //true
    cout << isPermutation(s1, s5) << endl; //false
    cout << isPermutation(s1, s6) << endl; //false
    cout << isPermutation(s3, s2) << endl; // false
    // cout << isPermutation(s4, s2) << endl; // false, error here
    // cout << isPermutation(s3, s4) << endl; // false, error here
    // cout << isPermutation(s4, s4) << endl; // true, error here
    cout << isPermutation(s3, s3) << endl; // ture
    return 0;
}

bool isPermutation(string s1, string s2) {
    if (s1.empty() && s2.empty()) return true;
    if (s1.empty() && !s2.empty()) return false;
    if (!s1.empty() && s2.empty()) return false;
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1.compare(s2) == 0;
}