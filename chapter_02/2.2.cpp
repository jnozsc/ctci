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

LinkedListNode* nthToLast(LinkedListNode* head, int k);

int main(int argc, const char* argv[]) {
    // insert code here...
    LinkedListNode* n1 = new LinkedListNode;
    LinkedListNode* n2 = new LinkedListNode;
    LinkedListNode* n3 = new LinkedListNode;
    LinkedListNode* n4 = new LinkedListNode;
    LinkedListNode* n5 = new LinkedListNode;
    LinkedListNode* n6 = new LinkedListNode;
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
    LinkedListNode* n7 = nthToLast(n1, 5);
    cout << n7->val << endl; // 2
    return 0;
}

LinkedListNode* nthToLast(LinkedListNode* head, int k) {
    if (k <= 0) {
        return NULL;
    }
    LinkedListNode* p1 = head;
    LinkedListNode* p2 = head;
    for (int i = 0; i < k - 1; i++) {
        if (p2 != NULL) {
            p2 = p2->next;
        } else {
            return NULL;
        }
    }
    if (p2 == NULL) {
        return NULL;
    }
    while (p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}