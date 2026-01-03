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
    int ans =0;
    int maxi=INT_MIN;
    vector<int>v;
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        v.push_back(root->val);
        maxi = INT_MIN;
        // here we are maintaining  a vector v to store the path to the
        // current node , we do it by pushing in the nodes value 
        // whenever you first enter it and pop it back while leaving it 
        // the left subtree wont interfeer with the right subtree then 
        // then after pushing it in we check for the maximum value until then
        // and check if the current nodes value is equal or greater than that
        // ( only equal possible though since you already added the node)
        // a mistake i did here was i didnt properly analyse the case no node
        // at all and only one node , since i initialised ans to 1 i had to return 
        // ans-1 since it would be counting root twice luckily there was no
        // test case where the root itself was one , coming to complexity 
        // it goes through each node once and the max length of v would be h
        // hence its O(h*n); 
        for(int i=0;i<v.size();i++){
            maxi = max(maxi,v[i]);
        }
        if(root->val >= maxi){
            ans++;
        }
        goodNodes(root->left);
        goodNodes(root->right);
        v.pop_back();
        return ans;
        
        }
    
};