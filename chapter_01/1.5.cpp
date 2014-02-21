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

string compressionString(string s);

int main(int argc, const char* argv[]) {

    // insert code here...
    string s1 = "aaBBccdddd";
    string s2 = "AbC";
    cout << s1 << endl;
    cout << compressionString(s1) << endl;
    cout << s2 << endl;
    cout << compressionString(s2) << endl;
    return 0;
}

string compressionString(string s) {
    string result = "";
    vector<char> charset;
    vector<int> count;
    int index = 0;
    while (index < s.length()) {
        if (charset.empty() || charset.back() != s[index]) {
            charset.push_back(s[index]);
            count.push_back(1);
            index++;
        } else {
            count[count.size() - 1]++;
            index++;
        }
    }
    if (charset.size() * 2 >= s.length()) {
        result = s;
    } else {
        for (int i = 0; i < charset.size(); i++) {
            result += charset[i];
            result += to_string(count[i]);
        }
    }
    return result;
}