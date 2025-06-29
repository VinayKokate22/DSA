class Solution {
public:
    long long binpow(long long val,long long b,long long mod){
        
        long long ans=1;

        while(b){
            if(b&1){
                ans=(ans*val)%mod;
            }
            val=(val*val)%mod;
            b=b>>1;
        }
        return ans;
    }
    int solve(int start,vector<int>&nums,int val){

        int end=nums.size()-1;

        int ans=-1;

        int mid;
        while(start<=end){
            mid=(end-start)/2+start;
            if(nums[mid]<=val){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }

        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {



        sort(nums.begin(),nums.end());

        long long ans=0;
        long long mod=1e9+7;
        int n=nums.size();
        for(long long i=0;i<n;i++){
            if(nums[i]>target)break;
            long long index=solve(i,nums,target-nums[i]);
            if(index!=-1)ans=(ans+binpow(2*1LL,index-i,mod))%mod;
            
        }
        return (int)ans;
    }

};