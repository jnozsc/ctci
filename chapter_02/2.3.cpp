//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

struct LinkedListNode {
    int val;
    struct LinkedListNode* next;
};

bool deleteNode(LinkedListNode* n);

int main(int argc, const char* argv[]) {
    // insert code here...
    LinkedListNode* n1 = new LinkedListNode ;
    LinkedListNode* n2 = new LinkedListNode   ;
    LinkedListNode* n3 = new LinkedListNode  ;
    LinkedListNode* n4 = new LinkedListNode   ;
    LinkedListNode* n5 = new LinkedListNode  ;
    LinkedListNode* n6 = new LinkedListNode  ;
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    n6->val = 6;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    // deleteDups(n1);
    deleteNode(n3);
    cout << n2->next->val << endl; // 4
    return 0;
}

bool deleteNode(LinkedListNode* n) {
    if (n == NULL || n->next == NULL) {
        return false; // error handle
    } else {
        n->val = n->next->val;
        n->next = n->next->next;
        return true;
    }
}