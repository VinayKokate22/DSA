class Solution {
public:
    int solve(long long val,vector<int>&nums){
        int start=0;
        int end=nums.size()-1;

        int mid;
        int ans=-1;
        while(start<=end){
            mid=(end-start)/2+start;
            if(1LL*nums[mid]<=val){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int index=solve(1LL*nums[i]*k,nums);
            if(index>=i)ans=min(ans,n-(index-i+1));
        }
        return ans;
    }
};;;;;;
