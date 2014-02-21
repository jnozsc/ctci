//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct LinkedListNode {
    int val;
    struct LinkedListNode* next;
};

bool isPalindrome(LinkedListNode* head);

int main(int argc, const char* argv[]) {
    // insert code here...
    LinkedListNode* n1 = new LinkedListNode;
    LinkedListNode* n2 = new LinkedListNode;
    LinkedListNode* n3 = new LinkedListNode;
    LinkedListNode* n4 = new LinkedListNode;
    LinkedListNode* n5 = new LinkedListNode;
    n1->val = 0;
    n2->val = 1;
    n3->val = 2;
    n4->val = 1;
    n5->val = 0;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    cout << boolalpha << isPalindrome(n1) << endl; // true;
    n4->val = 5;
    cout << boolalpha << isPalindrome(n1) << endl; // false;
    return 0;
}

bool isPalindrome(LinkedListNode* head) {
    LinkedListNode* slow = head;
    LinkedListNode* fast = head;
    vector<int> myVector;
    while (fast && fast->next) {
        myVector.push_back(slow->val);
        slow = slow -> next;
        fast =  fast -> next -> next;
    }
    if (fast) {
        slow = slow->next;
    }
    while (slow) {
        int top = myVector.back();
        myVector.pop_back();
        if (top != slow->val) {
            return false;
        }
        slow = slow->next;
    }
    return true;
}