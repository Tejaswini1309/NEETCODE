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
    bool pathfinder(TreeNode* root,TreeNode* p,vector<TreeNode*>&v){
        if(root==NULL){
            return false;
        }
        v.push_back(root);
        if(root == p){
            return true;
        }
        if(pathfinder(root->left,p,v) || pathfinder(root->right,p,v)){
            return true;
        }
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v;
        pathfinder(root,p,v);
        vector<TreeNode*>h;
        pathfinder(root,q,h);
        int i=0;
        TreeNode* ans;
        //firstly we defined a helper function which helps us keep track
        //of the path and instead of returning a vector it returns a bool 
        //value as if we use bool value once its true that is if p is found
        //it wont go back again , it wont alter the path and now after getting
        //the vectors !! again we must pass through reference !! we traverse from the beginning 
        //to find the node right after which they diverge as once they diverge 
        //we will not have any other common node in their path , 
        //this is much better than using a O(n2) method where you traverse from the
        //back of the vectors and try to find the first common element and 
        //well there are two more bugs here firstly you did not initialise ans 
        //and you do not handle the case of root == null add return null ptr 
        //in the beggining checking if root == NULL 
        while(i<v.size()and i<h.size() and v[i]==h[i]){
            ans = v[i];
            i++;
        }
        return ans;
    }
};