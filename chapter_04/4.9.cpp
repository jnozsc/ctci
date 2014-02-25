//
//  main.cpp
//  solution
//
//  Created by John on 2/18/14.
//  Copyright (c) 2014 John. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;         // The data in this node.
    TreeNode* left;   // Pointer to the left subtree.
    TreeNode* right;  // Pointer to the right subtree.
};

TreeNode*  createMinimalBST(int array[], int start, int end);
void printAllPath(TreeNode* root, int target, int orignal, string prefix);

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
    // creatLevelLinkedListRecursion(result,resultVector,0);
    cout << "debug" << endl;
    TreeNode* newNode = new TreeNode();
    newNode->val = 0;
    result->left->right->left = newNode;
    TreeNode* newNode_1 = new TreeNode();
    TreeNode* newNode_2 = new TreeNode();
    newNode_1->val = -1;
    newNode_2->val = 1;
    result->left->right->right = newNode_1;
    newNode_1->left = newNode_2;
    TreeNode* newNode_3 = new TreeNode();
    newNode_3->val = 4;
    result->right->left->left = newNode_3;
    // AND THEN CREATE LINKED LIST AND RELEASE SUB-VECTORS
    printAllPath(result, 9, 9, "");
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

void printAllPath(TreeNode* root, int target, int original, string prefix) {
    if (!root) {
        return;
    }
    if (root->val == target) {
        cout << prefix << root->val << endl;
    }
    printAllPath(root->left, original, original, "");
    //printAllPath (root->right,original,original,""); // why commit here, it will duplicate
    printAllPath(root->left, target - root->val, target, prefix + to_string(root->val) + "->");
    printAllPath(root->right, target - root->val, target, prefix + to_string(root->val) + "->");

}