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

LinkedListNode* addLists(LinkedListNode* l1, LinkedListNode* l2);

int main(int argc, const char* argv[]) {
    // insert code here...
    LinkedListNode* n1 = new LinkedListNode;
    LinkedListNode* n2 = new LinkedListNode;
    LinkedListNode* n3 = new LinkedListNode;
    LinkedListNode* n4 = new LinkedListNode;
    LinkedListNode* n5 = new LinkedListNode;
    LinkedListNode* n6 = new LinkedListNode;
    n1->val = 7;
    n2->val = 1;
    n3->val = 6;
    n4->val = 5;
    n5->val = 9;
    n6->val = 2;
    n1->next = n2;
    n2->next = n3;
    n4->next = n5;
    n5->next = n6;
    LinkedListNode* n7 = addLists(n1, n4);
    cout << n7->val << endl; // 4
    cout << n7->next->val << endl;
    cout << n7->next->next->val << endl;
    return 0;
}

LinkedListNode* addLists(LinkedListNode* l1, LinkedListNode* l2) {
    LinkedListNode* result = new LinkedListNode;
    LinkedListNode* tmp = new LinkedListNode;
    result->next = tmp;
    int digit;
    int carry = false;
    while (l1 || l2) {
        digit = 0;
        if (l1) {
            digit += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            digit += l2->val;
            l2 = l2->next;
        }
        if (carry) {
            digit ++;
        }
        if (digit >= 10) {
            carry = true;
            digit -= 10;
        } else {
            carry = false;
        }
        tmp->val = digit;
        tmp->next = new LinkedListNode;
        tmp = tmp->next;
    }
    return result->next;
}