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
// we do inorder traversal just check for the root and keep moving 
// downwards if at some point the val of a node and the root of the 
// subroot are the same then we check for the similarity of subroot and
// the subtree of that node , if satisfied we return true , make sure 
// you dont just check once if you encounter a similar node ( same val )
// and just return false it may be further below so dont return false
// if not satisfied in between the tree and if in case the subroot 
// need not be a subtree exactly but it must just be present in there 
// if we encounter null in subroot we will always return true
// it may or maynot pass for a few nodes in the subroots last level , but it 
// will stop once its found a similar tree 
    bool same(TreeNode* root , TreeNode* subRoot){
        if(root == NULL and subRoot == NULL){
            return true;
        }
        if(root!=NULL and subRoot==NULL){
            return false;
        }
        if(root == NULL and subRoot!=NULL){
            return false;
        }
        return ( (root->val==subRoot->val) and same(root->left,subRoot->left) and same(root->right,subRoot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL and root==NULL){
            return true;
        }
        if(root==NULL){
            return false ;
        }
        if(root->val == subRoot->val and same(root,subRoot)){
            return true;
        }
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};