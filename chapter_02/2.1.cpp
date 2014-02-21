//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

struct LinkedListNode {
    int val;
    struct LinkedListNode* next;
};

void deleteDups(LinkedListNode* n);

int main(int argc, const char* argv[]) {
    // insert code here...
    LinkedListNode* n1 = new LinkedListNode;
    LinkedListNode* n2 = new LinkedListNode;
    LinkedListNode* n3 = new LinkedListNode;
    LinkedListNode* n4 = new LinkedListNode;
    LinkedListNode* n5 = new LinkedListNode;
    LinkedListNode* n6 = new LinkedListNode;
    n1->val = 1;
    n2->val = 1;
    n3->val = 1;
    n4->val = 2;
    n5->val = 1;
    n6->val = 1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    deleteDups(n1);
    return 0;
}

void deleteDups(LinkedListNode* n) {
    set<int> myset;
    LinkedListNode* previous = NULL;
    while (n != NULL) {
        if (myset.find(n->val) != myset.end()) {
            previous->next = n->next;
        } else {
            myset.insert(n->val);
            previous = n;
        }
        n = n->next;
    }
}