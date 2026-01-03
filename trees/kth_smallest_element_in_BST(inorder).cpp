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
    vector<int> inorder(TreeNode* root){
        if(root==NULL){
            return v;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return v;
    }
    // since preorder traversal of a BST returns the ascending order
    // of elements in the BST , we first do inorder get the sorted 
    // vector and return the element at index k-1
    // inorder -> left,myself,right
    // preorder -> myself,left,right
    // postorder -> left,right,myself
    int kthSmallest(TreeNode* root, int k) {
        vector<int>s = inorder(root);
        return s[k-1];
    }
};