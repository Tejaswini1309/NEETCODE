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
    int maxlevel=0;
    vector<int>v;
    vector<int> preorder(TreeNode* root,int level){
        if(root==NULL){
            return v;
        }
        if(level>maxlevel){
            v.push_back(root->val);
            maxlevel = level;
        }
        preorder(root->right,level+1);
        preorder(root->left,level+1);
        return v;
    }
    // here basically for every level we have to print the rightmost element
    // wkt if it were a regular preorder traversal eg: we go myself , left, right
    // if it enters a new level it would enter the leftmost node first
    // so to get a left view you would have to print the first node 
    // that has a new max level to it , so similarly for a right view 
    // we just change the order to right then left 
    // this can also be solved using the level order traversal method
    // if it were a left side view problem , or even right side 
    // for right side print the element just before the null and for 
    // left side view the element just after null in both cases print
    // the root 
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
       if(root==NULL){
            return ans;
       }
       return preorder(root,1);
    }
};