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
    TreeNode* invertTree(TreeNode* root) {
        // for every node we swap its left and right children ,
        // and since we have to return root node for each case
        // we will return null if the node is null 
        if(root==NULL){
            return NULL;
        }
        auto x = root->left;
        root->left=root->right;
        root->right=x;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};