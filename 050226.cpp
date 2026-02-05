class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int index=i;
            if(nums[i]>0){
                index=(index+nums[i])%n;
                ans.push_back(nums[index]);
            }
            else if(nums[i]<0){
                index=(index+(nums[i])%n+n)%n;
                cout<<index<<endl;
                ans.push_back(nums[index]);
            }
            else ans.push_back(nums[index]);
        }
        return ans;
    }
};