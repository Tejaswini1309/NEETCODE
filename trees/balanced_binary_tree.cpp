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
// for every node you have to check if the diff between maxheights 
// of its left and right subtrees are at most one and also check if
// both its children follow this property hence if all 3 of them are 
// true you return true else false , to calculate maxheight we use
// the function maxheight 
    int maxheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(maxheight(root->left),maxheight(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool x;
        if(abs(maxheight(root->left)-maxheight(root->right)) <=1 ){
            x = true;
        }
        else{
            x=false;
        }
        return(x and isBalanced(root->left) and isBalanced(root->right));
    }
};