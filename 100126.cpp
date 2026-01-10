class Solution {
public:
    int solve(string &s1,string &s2,int &n,int &m,int i,int j,vector<vector<int>>&dp){
        if(i>=n || j>=m){
            int val=0;
            while(j<m){
                val+=(int)s2[j];
                j++;
            }
            while(i<n){
                val+=s1[i];
                i++;
            }
            return val;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int val=INT_MAX;
        if(s1[i]==s2[j]){
            val=solve(s1,s2,n,m,i+1,j+1,dp);
        }
        val=min(val,(int)s1[i]+solve(s1,s2,n,m,i+1,j,dp));
        val=min(val,(int)s2[j]+solve(s1,s2,n,m,i,j+1,dp));

        return dp[i][j]=val;
        
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s1,s2,n,m,0,0,dp);
    }
};