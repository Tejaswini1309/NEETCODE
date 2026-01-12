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
    // for a tree to be a BST we know that all nodes must be unique and
    // its inorder traveral must result in ascending order of the nodal
    // values , hence calculate 
    bool isValidBST(TreeNode* root) {
        vector<int>x = inorder(root);
        int n=x.size();
        for(int i=1;i<n;++i){
            if(x[i]<=x[i-1]){
                return false;
            }
        }
        return true;
    }
};
