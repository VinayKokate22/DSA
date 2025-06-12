#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums){
    nums.push_back(nums[0]);
    int ans=INT_MIN;
    for(int i=1;i<nums.size();i++){
        ans=max(ans,abs(nums[i]-nums[i-1]));
    }
    return ans;
};
int main(){
    vector<int>nums;
    solve(nums);
    return 0;
}
