class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>ans;

        int n=nums.size();
        int index=0;
        int limit=0;
        while(index<n){
            if(nums[index]==key){
                limit=k;
                ans.insert(index);
            }
            else if(limit>0){
                ans.insert(index);
                limit--;
            }
            index++;
        }
        index=n-1;
        limit=0;
        while(index>=0){
            if(nums[index]==key){
                limit=k;
                ans.insert(index);
            }
            else if(limit>0){
                ans.insert(index);
                limit--;
            }
            index--;
        }
        vector<int>v;
        for(auto it:ans){
            v.push_back(it);
        }
        return v;
    }
};