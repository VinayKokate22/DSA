class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=2;i<nums.size();i+=3){
           
            if( (nums[i]-nums[i-2]) >k )return {};
            
            ans.push_back({nums[i],nums[i-1],nums[i-2]});
        }
        return ans;
    }   


};