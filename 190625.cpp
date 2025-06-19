class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        

        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0;
        int start=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]-nums[start]>k){
                ans++;
                start=i;
            }
            i++;
        }
        return ans+1;
    }
};