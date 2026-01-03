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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>v;
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode* >q;
        q.push(root);
        q.push(NULL);
        // so here we maintain a queue such that after every layer we
        // add NULL to it , ( how is it done ? you first add null after
        // adding root node then keep adding another null everytime you 
        // encounter another null , thats like when you add the last node
        // of that layer) , also each time you encounter null push back v
        // into ans and clear it for the next layer to be added , and when
        // to exit the loop ? its when you encounter the last null , when
        // the size is zero you exit the loop 

        // time complexity - O(n), n being the number of nodes 
        // space complexity - O(w), w is the width of the tree [ since 
        // at an instant one layer stays in the queue with a null , so its
        // w +1 ]
        while(q.size()!=0){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(v);
                v.clear();
                if(q.size()!=0){
                q.push(NULL);
                }
                continue;
            }
            v.push_back(curr->val);
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        return ans;
    }
};