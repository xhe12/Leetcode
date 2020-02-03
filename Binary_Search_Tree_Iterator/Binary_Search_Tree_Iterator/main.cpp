//
//  main.cpp
//  Binary_Search_Tree_Iterator
//
//  Created by Sharon He on 2/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
       int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class BSTIterator {
    vector<TreeNode*> leftNodes;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            leftNodes.push_back(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *lastNode = leftNodes.back();
        leftNodes.pop_back();
        
        TreeNode *cur = lastNode;
        cur = cur->right;
        if(cur){
            leftNodes.push_back(cur);
            while(cur->left){
                leftNodes.push_back(cur->left);
                cur = cur->left;
            }
        }
        return lastNode->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !leftNodes.empty();
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(2);
    TreeNode *node = new TreeNode(1);
    root->left = node;
    BSTIterator* solution = new BSTIterator(root);
    solution->hasNext();
    solution->next();
    solution->hasNext();
    solution->next();
    solution->hasNext();
    
    delete root;
    delete node;
    return 0;
}
