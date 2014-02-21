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

LinkedListNode* FindBeginning(LinkedListNode* head);

int main(int argc, const char* argv[]) {
    // insert code here...
    LinkedListNode* n1 = new LinkedListNode;
    LinkedListNode* n2 = new LinkedListNode;
    LinkedListNode* n3 = new LinkedListNode;
    LinkedListNode* n4 = new LinkedListNode;
    LinkedListNode* n5 = new LinkedListNode;
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;
    LinkedListNode* n7 = FindBeginning(n1);
    cout << n7->val << endl; // 3
    return 0;
}

LinkedListNode* FindBeginning(LinkedListNode* head) {
    LinkedListNode* slow = head;
    LinkedListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}