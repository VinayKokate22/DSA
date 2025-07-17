class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k , 0));
        int ml = 0;
    
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    int rem = (nums[j] + nums[i]) % k ;
                        dp[j][rem] = max(dp[j][rem], dp[i][rem] + 1);

                        ml = max(dp[j][rem], ml);
                    }
                }
            

        return ml + 1;
    }
};