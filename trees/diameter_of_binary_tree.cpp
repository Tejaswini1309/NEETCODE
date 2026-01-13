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
// here we traverse through every node of the tree and we calculate the 
// max diameter encountered till now , for any node the max diameter 
// would be its left subtree height + right subtree height -2( cuz , 
// we just need the longest path and if we look at it from one side
// the longest path would be the path leading to the max depth 
// on that side , since we want edges its height -1 on either side ) , we 
// traverse through each node and check the max among itself and its 
// children and hence we find the diameter of the tree 
    int maxheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(maxheight(root->left),maxheight(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return max(maxheight(root->left)+maxheight(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};