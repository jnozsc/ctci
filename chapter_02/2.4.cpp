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

LinkedListNode* partition(LinkedListNode* n, int x);

int main(int argc, const char* argv[]) {
    // insert code here...
    LinkedListNode* n1 = new LinkedListNode;
    LinkedListNode* n2 = new LinkedListNode;
    LinkedListNode* n3 = new LinkedListNode;
    LinkedListNode* n4 = new LinkedListNode;
    LinkedListNode* n5 = new LinkedListNode;
    LinkedListNode* n6 = new LinkedListNode;
    n1->val = 6;
    n2->val = 5;
    n3->val = 4;
    n4->val = 3;
    n5->val = 2;
    n6->val = 1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    LinkedListNode* n7 = partition(n1, 3);
    cout << n7->val << endl; // 1
    cout << n7->next->val << endl; // 2
    cout << n7->next->next->val << endl; // 3
    cout << n7->next->next->next->val << endl; // 4
    cout << n7->next->next->next->next->val << endl; // 5
    cout << n7->next->next->next->next->next->val << endl; //6
    return 0;
}

LinkedListNode* partition(LinkedListNode* n, int x) {
    LinkedListNode* beforeStart = NULL;
    LinkedListNode* afterStart = NULL;
    while (n) {
        LinkedListNode* next = n->next;
        if (n->val < x) {
            n->next = beforeStart;
            beforeStart = n;
        } else {
            n->next = afterStart;
            afterStart = n;
        }
        n = next;
    }
    if (beforeStart == NULL) {
        return afterStart;
    }
    LinkedListNode* head = beforeStart;
    while (beforeStart->next) {
        beforeStart = beforeStart->next;
    }
    beforeStart->next = afterStart;
    return head;
}