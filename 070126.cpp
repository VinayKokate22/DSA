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
    int solve(TreeNode* root,vector<int>&v){
        if(!root->left && !root->right){
            v.push_back(root->val);
            return root->val;
        }
        int left=0;
        int right=0;
        if(root->left)left=solve(root->left,v);
        if(root->right)right=solve(root->right,v);
        v.push_back(root->val+left+right);
        return left+right+root->val;
    }
    int maxProduct(TreeNode* root) {
        vector<int>v;
        int sum=solve(root,v);
        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<v.size();i++){
            long long val=((1LL*(sum-v[i]))*(1LL*v[i]));
            // cout<<sum-v[i]<<" "<<v[i]<<endl;
            ans=max(ans,val);
        }
        ans=ans%mod;
        return (int)ans;
    }
};