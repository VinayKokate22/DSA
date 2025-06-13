class Solution {
public:
    bool valid(int &val,vector<int>&nums,int &p){
        int i=1;
        int n=nums.size();
        int count=0;
        while(i<n){
            if(nums[i]-nums[i-1]<=val){
                count++;
                if(count>=p)return true;
                i+=2;
            }
            else i++;
        }
        
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=0;
        int end=1e9;
        int ans=-1;
        while(start<=end){
            int mid=(end-start)/2+start;
            if(valid(mid,nums,p)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};
// 0 0 0 1 3 5 6