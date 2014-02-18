//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

bool isUnique(string s);

int main(int argc, const char* argv[]) {

    // insert code here...
    std::cout << "Hello, World!\n";
    string a = "abcde";
    string b = "abcda";
    cout << isUnique(a) << endl;
    cout << isUnique(b) << endl;
    return 0;
}

bool isUnique(string s) {
    if (s.length() > 256) return false;
    map<char, bool> mymap;
    for (int i = 0; i < 256; i++) {
        mymap[i] = false;
    }
    for (int j = 0; j < s.length(); j++) {
        if (mymap[s[j]] == false) {
            mymap[s[j]] = true;
        } else {
            return false;
        }
    }
    return true;
}