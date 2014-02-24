//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

enum animal {
    cat, dog
};

struct LinkedListNode {
    int id;
    animal animal;
    struct LinkedListNode* next;
};

LinkedListNode* dequeueAny(LinkedListNode* list);
LinkedListNode* enqueue(LinkedListNode* list, LinkedListNode* new_animal);
LinkedListNode* dequeueDog(LinkedListNode* list);
LinkedListNode* dequeueCat(LinkedListNode* list);

int main(int argc, const char* argv[]) {
    // insert code here...
    // hanoi(8);
    LinkedListNode* cat1 = new LinkedListNode();
    cat1->id = 1;
    cat1->animal = cat;
    LinkedListNode* dog1 = new LinkedListNode();
    dog1->id = 2;
    dog1->animal = dog;
    LinkedListNode* dog2 = new LinkedListNode();
    dog2->id = 3;
    dog2->animal = dog;
    LinkedListNode* list = enqueue(cat1, dog1);
    list = enqueue(list, dog2);
    dequeueAny(list); // get cat
    dequeueDog(list); // get dog 1
    dequeueCat(list); // get nothing
    return 0;
}

LinkedListNode* enqueue(LinkedListNode* list, LinkedListNode* new_animal) {
    if (!list) {
        return  new_animal;
    } else {
        LinkedListNode* head = new LinkedListNode;
        head -> next = list;
        while (list->next) {
            list = list->next;
        }
        list->next = new_animal;
        return head->next;
    }
}

LinkedListNode* dequeueAny(LinkedListNode* list) {
    if (!list) {
        return NULL;
    } else {
        cout << "you get ";
        if (list->animal == dog) {
            cout << "dog";
        } else {
            cout << "cat";
        }
        cout << " #id " << list->id << endl;
        return list->next;
    }
}

LinkedListNode* dequeueDog(LinkedListNode* list) {
    if (!list) {
        return NULL;
    } else {
        if (list && !list->next) {
            if (list->animal == dog) {
                cout << "you get dog #id " << list->id << endl;
                list = list->next;
            } else {
                cout << "no dog availble" << endl;
            }
            return list;
        }
        LinkedListNode* head = new LinkedListNode();
        head -> next = list;
        while (list && list->next) {
            if (list->next->animal == dog) {
                cout << "you get dog #id " << list->next->id << endl;
                list->next = list->next->next;
                return head->next;
            }
            list = list->next;
        }
        cout << "no dog availble" << endl;
        return head->next;
    }
}

LinkedListNode* dequeueCat(LinkedListNode* list) {
    if (!list) {
        return NULL;
    } else {
        if (list && !list->next) {
            if (list->animal == cat) {
                cout << "you get cat #id " << list->id << endl;
                list = list->next;
            } else {
                cout << "no cat availble" << endl;
            }
            return list;
        }
        LinkedListNode* head = new LinkedListNode();
        head -> next = list;
        while (list && list->next) {
            if (list->next->animal == cat) {
                cout << "you get cat #id " << list->next->id << endl;
                list->next = list->next->next;
                return head->next;
            }
            list = list->next;
        }
        cout << "no cat availble" << endl;
        return head->next;
    }
}
