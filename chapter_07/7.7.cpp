//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int getKthMagicNumber(int k);

int main(int argc, const char* argv[]) {
    // insert code here...
    for (int i = 1; i <= 20; i++) {
        cout << i << "th magic number is " << getKthMagicNumber(i) << endl;
    }
    return 0;
}

int getKthMagicNumber(int k) {
    vector<int> magicNumbers;
    deque<int> candidates;
    candidates.push_back(3);
    candidates.push_back(5);
    candidates.push_back(7);
    // assume k starts from 1
    while (magicNumbers.size() < k) {
        int tmp = candidates.front();
        candidates.pop_front();
        if (magicNumbers.empty() || tmp != magicNumbers[magicNumbers.size() - 1]) {
            candidates.push_back(tmp * 3);
            candidates.push_back(tmp * 5);
            candidates.push_back(tmp * 7);
            sort(candidates.begin(), candidates.end());
            magicNumbers.push_back(tmp);
        }
    }
    return magicNumbers[k - 1];
}