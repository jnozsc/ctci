//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;         // The data in this node.
    TreeNode* left;   // Pointer to the left subtree.
    TreeNode* right;  // Pointer to the right subtree.
};

struct LinkedListNode {
    int val;
    struct LinkedListNode* next;
};

TreeNode*  createMinimalBST(int array[], int start, int end);
void creatLevelLinkedListRecursion(TreeNode* root, vector<vector<int>>& myVector, int level);

int main(int argc, const char* argv[]) {
    // insert code here...
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* result = createMinimalBST(array, 0, sizeof(array) / sizeof(*array) - 1);
    cout << "  " << result->val << endl;
    cout << " " << result -> left->val << "  " << result->right->val << endl;
    cout << result -> left->left->val << " " << result->left->right->val <<  " " << result->right->left->val <<  " " << result->right->right->val << endl;
    // cout << boolalpha << isBST(result) << endl; // true
    // result->left->right->val=1;
    //  cout << boolalpha << isBST(result) << endl; // false
    vector<vector<int>> resultVector;
    creatLevelLinkedListRecursion(result, resultVector, 0);
    cout << "debug" << endl;
    // AND THEN CREATE LINKED LIST AND RELEASE SUB-VECTORS
    return 0;
}

TreeNode*  createMinimalBST(int array[], int start, int end) {
    if (start > end) return NULL;
    else if (start == end) {
        TreeNode* result = new TreeNode;
        result->val = array[start];
        return result;
    } else {
        TreeNode* result = new TreeNode;
        result->val = array[(start + end) / 2];
        result->left = createMinimalBST(array, start, (start + end) / 2 - 1);
        result->right = createMinimalBST(array, (start + end) / 2 + 1, end);
        return result;
    }
}

void creatLevelLinkedListRecursion(TreeNode* root, vector<vector<int>>& myVector, int level) {
    if (!root) {
        return;
    } else {
        if (myVector.empty() || myVector.size() - 1 < level) {
            vector<int> subVector;
            subVector.push_back(root->val);
            myVector.push_back(subVector);
        } else {
            myVector[level].push_back(root->val);
        }
        creatLevelLinkedListRecursion(root->left, myVector, level + 1);
        creatLevelLinkedListRecursion(root->right, myVector, level + 1);
    }
}
