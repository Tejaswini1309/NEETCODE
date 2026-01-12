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
// for every node we check if its values are equal and also call 
// the function for its children , it returns true only if the 
// vals are equal on both its left subtree right subtree and itself 
// edge cases are when both are null ( true ) either one of them is
// false while the other isnt ( false )
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL){
            return true;
        }
        else if(p==NULL and q!=NULL){
            return false;
        }
        else if(p!=NULL and q==NULL){
            return false;
        }
        return ((p->val==q->val)and isSameTree(p->left,q->left) and isSameTree(p->right,q->right));
    }
};