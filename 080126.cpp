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
    void  solve(TreeNode* root,vector<TreeNode*>&v){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            v={};
            while(size--){
                v.push_back(q.front());
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        
    }
    TreeNode* findans(TreeNode*root,vector<TreeNode*>v){
        if(!root)return NULL;

        for(auto it:v){
            // cout<<it->val<<endl;
            if(it->val==root->val)return root;
        }
        TreeNode* left=findans(root->left,v);
        TreeNode* right=findans(root->right,v);

        if(left && right)return root;
        if(left)return left;
        if(right)return right;
        return NULL; 
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*>v;
        solve(root,v);
        
        return findans(root,v);
    }
};