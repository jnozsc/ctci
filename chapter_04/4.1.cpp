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

int height(TreeNode* root);
bool isBalnace(TreeNode* root);

int main(int argc, const char* argv[]) {
    // insert code here...
    TreeNode* n1 = new TreeNode();
    TreeNode* n2 = new TreeNode();
    TreeNode* n3 = new TreeNode();
    cout << height(n1) << endl;
    n1 ->left = n2;
    cout << height(n1) << endl;
    n1 -> right = n3;
    cout << height(n1) << endl;
    cout << boolalpha << isBalnace(n1) << endl; // true;
    TreeNode* n4 = new TreeNode();
    TreeNode* n5 = new TreeNode();
    TreeNode* n6 = new TreeNode();
    n4->left = n5;
    n5->right = n6;
    cout << boolalpha << isBalnace(n4) << endl; // false;
    return 0;
}

int height(TreeNode* root) {
    if (!root) {
        return 0;
    } else {
        return max(height(root->left) + 1, height(root->right) + 1);
    }
}

bool isBalnace(TreeNode* root) {
    if (!root) {
        return true;
    } else {
        return abs(height(root->left) - height(root->right) <= 1) && isBalnace(root->left) && isBalnace(root->right);
    }
}