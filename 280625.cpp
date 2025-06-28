class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        int size=k;
        sort(v.begin(),v.end());

        vector<pair<int,int>>ans(k,{0,0});
        
        for(int i=n-1;i>=0;i--){
            ans[k-1]=v[i];
            k--;
            if(k<=0){
                break;
            }
        }
        sort(ans.begin(),ans.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });
        vector<int>res;
        for(auto it:ans){
            res.push_back(it.first);
        }
        return res;

    }
};