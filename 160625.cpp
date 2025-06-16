class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int minv=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>minv){
                ans=max(ans,nums[i]-minv);
            }
            minv=min(nums[i],minv);
        }
        return ans;
    }
};