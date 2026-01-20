class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans.push_back(-1);
            }
            else{
                int temp=nums[i]+1;
                int temp2=!temp;
                temp=temp&nums[i];
                temp2=temp2&nums[i];
                int val=temp^nums[i];
                ans.push_back(temp+val/2);
            }
        }
        return ans;
    }
};