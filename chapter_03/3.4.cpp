//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

void hanoi(int level);
void hanoiRecursion(stack<int>  from_stack, stack<int>  to_stack, stack<int>  tmp_stack, int from, int to, int tmp);

int main(int argc, const char* argv[]) {
    // insert code here...
    hanoi(8);
    return 0;
}

void hanoi(int level) {
    stack<int> hanoi;
    for (int i = level; i > 0; i--) {
        hanoi.push(i);
    }
    stack<int> empty_1;
    stack<int> empty_2;
    hanoiRecursion(hanoi, empty_1, empty_2, 1, 3, 2);
}

void hanoiRecursion(stack<int>  from_stack, stack<int>  to_stack, stack<int>  tmp_stack, int from, int to, int tmp) {
    if (from_stack.size() == 1) {
        cout << "move " << from_stack.top() << " from " << from << " to " << to << endl;
        to_stack.push(from_stack.top());
        from_stack.pop();
    } else {
        stack<int> topRev;
        stack<int> top;
        while (from_stack.size() > 1) {
            topRev.push(from_stack.top());
            from_stack.pop();
        }
        while (!topRev.empty()) {
            top.push(topRev.top());
            topRev.pop();
        }
        hanoiRecursion(top, tmp_stack, to_stack, from, tmp, to);
        hanoiRecursion(from_stack, to_stack, tmp_stack, from, to, tmp);
        hanoiRecursion(top, to_stack, from_stack, tmp, to, from);
    }
}