//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

int updateBits(int N, int M, int i, int j);

int main(int argc, const char* argv[]) {
    // insert code here...
    int N = 0b10000000000;
    int M = 0b10011;
    cout << (bitset<32>)updateBits(N, M, 2, 6) << endl ;
    //cout << (bitset<4>)(0b1011&(~0<<2)) << endl;
    return 0;
}

int updateBits(int n, int m, int i, int j) {
    int allOnes = ~0;
    int left = allOnes << (j + 1);
    int right = ((1 << i) - 1);
    int mask = left | right;
    int n_cleared = n & mask;
    int m_shifted = m << i;
    return n_cleared | m_shifted;
}