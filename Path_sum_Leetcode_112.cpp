/*
Problem Statement :-
Given the root of a binary tree and an integer target, return true if
the tree has a root-to-leaf path such that sum of all nodes along that
path equals target.

*/
#include <iostream>

using namespace std;

bool helper(TreeNode* node, int target, int sum)
{
    if(node == NULL)
    {
        return false;
    }
    if(node->left == NULL && node->right == NULL)
    {
        return (node->val + sum == target);
    }
    return (helper(node->left, target, node->val + sum) || 
    helper(node->right, target, node->val + sum));
}

int main()
{
    TreeNode* root;
    int target = 10;
    cout << helper(root, target, 0) << endl;
    return 0;
}
