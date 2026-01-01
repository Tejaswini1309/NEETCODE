/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int>v;
    vector<int> preorder(TreeNode* root){
        if(root==NULL){
            return v;
        }
        preorder(root->left);
        v.push_back(root->val);
        preorder(root->right);
        return v;
    }
    // since preorder traversal of a BST returns the ascending order
    // of elements in the BST , we first do preorder get the sorted 
    // vector and return the element at index k-1
    int kthSmallest(TreeNode* root, int k) {
        vector<int>s = preorder(root);
        return s[k-1];
    }
};