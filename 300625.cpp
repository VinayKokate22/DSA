class Solution {
public:
    int findLHS(vector<int>& nums) {


        sort(nums.begin(),nums.end());

        int start=0;
        int end=0;

        int n=nums.size();

        int ans=0;

        while(end<n){
            while(nums[end]-nums[start]>1){
                start++;
            }
            if((nums[end]-nums[start])==1)ans=max(ans,end-start+1);
            end++;
        }

        return ans;
    }
};