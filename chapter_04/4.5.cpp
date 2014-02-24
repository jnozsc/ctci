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
bool isBST(TreeNode* root);

int main(int argc, const char* argv[]) {
    // insert code here...
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* result = createMinimalBST(array, 0, sizeof(array) / sizeof(*array) - 1);
    cout << "  " << result->val << endl;
    cout << " " << result -> left->val << "  " << result->right->val << endl;
    cout << result -> left->left->val << " " << result->left->right->val <<  " " << result->right->left->val <<  " " << result->right->right->val << endl;
    cout << boolalpha << isBST(result) << endl; // true
    result->left->right->val = 1;
    cout << boolalpha << isBST(result) << endl; // false
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

bool isBST(TreeNode* root) {
    if (!root) {
        return true;
    } else {
        return ((root->left && root->left->val <= root->val) || !root->left) && ((root->right && root->right->val >= root->val) || !root->right) && isBST(root->left) && isBST(root->right);
    }
}