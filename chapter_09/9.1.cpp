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

int countWays(int stairs);
int countWays(int stairs, map<int, int>& countWaysCache);

int main(int argc, const char* argv[]) {
    // insert code here...
    clock_t start, end;
    double timeUsed;
    map<int, int> countWaysCache;
    // fast, dynamic programming
    start = clock();
    for (int i = 1; i <= 30; i++) {
        cout << "For " << i << " stairs, there are " << countWays(i, countWaysCache) << " solutions " << endl;
    }
    end = clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "used " << timeUsed << " secondes" << endl;
    // slow, recursion
    start = clock();
    for (int i = 1; i <= 30; i++) {
        cout << "For " << i << " stairs, there are " << countWays(i) << " solutions " << endl;
    }
    end = clock();
    timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "used " << timeUsed << " secondes" << endl;
    return 0;
}

int countWays(int stairs) {
    if (stairs < 0) {
        return 0;
    } else if (stairs == 0) {
        return 1;
    } else {
        return countWays(stairs - 1) + countWays(stairs - 2) + countWays(stairs - 3);
    }
}

int countWays(int stairs, map<int, int>& countWaysCache) {
    if (stairs < 0) {
        return 0;
    } else if (stairs == 0) {
        if (countWaysCache.count(stairs)) {
            return countWaysCache[stairs];
        } else {
            countWaysCache[0] = 1;
            return countWaysCache[0];
        }
    } else {
        if (countWaysCache.count(stairs)) {
            return countWaysCache[stairs];
        }
        countWaysCache[stairs] = countWays(stairs - 1, countWaysCache) + countWays(stairs - 2, countWaysCache) + countWays(stairs - 3, countWaysCache);
        return countWaysCache[stairs] ;
    }
}