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

TreeNode*  createMinimalBST(int array[], int start, int end);
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q);

int main(int argc, const char* argv[]) {
    // insert code here...
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* result = createMinimalBST(array, 0, sizeof(array) / sizeof(*array) - 1);
    cout << "  " << result->val << endl;
    cout << " " << result -> left->val << "  " << result->right->val << endl;
    cout << result -> left->left->val << " " << result->left->right->val <<  " " << result->right->left->val <<  " " << result->right->right->val << endl;
    cout << "=====" << endl;
    TreeNode* lca = findLCA(result, result->left->right, result->right->left);
    cout << "lca is " << lca->val << endl; // 4
    lca = findLCA(result, result->right->right, result->right->left);
    cout << "lca is " << lca->val << endl; // 6
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

TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {

    // no root no LCA.
    if (!root) {
        return NULL;
    }

    // if either p or q is the root then root is LCA.
    if (root == p || root == q) {
        return root;
    } else {
        // get LCA of p and q in left subtree.
        TreeNode* l = findLCA(root->left , p, q);

        // get LCA of p and q in right subtree.
        TreeNode* r = findLCA(root->right , p, q);

        // if one of p or q is in leftsubtree and other is in right
        // then root it the LCA.
        if (l && r) {
            return root;
        }
        // else if l is not null, l is LCA.
        else if (l) {
            return l;
        } else {
            return r;
        }
    }
}