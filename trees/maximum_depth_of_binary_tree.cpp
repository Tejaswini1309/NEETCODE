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
    // this problem can be solved by recursion, to get
    // the max depth check the max depth of both your children
    // whoseevers is max add one to it , as this is done multiple times
    // the length of the longest path or the depth will be known (~_~) why does this sound like a... 
    // like a method to solve a circuit idk if thats explainable 
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};