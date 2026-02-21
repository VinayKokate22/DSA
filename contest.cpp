class Solution {
public:
    int solve(vector<vector<int>>&dp,string &s,int i,int j){
        if(i==j){
            return dp[i][j]= 0;
        }
        else if(i>j)return dp[i][j]= 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=INT_MAX;
        if(s[i]==s[j]){
            a=solve(dp,s,i+1,j-1);
        }
        int b=1+solve(dp,s,i+1,j);
        int c=1+solve(dp,s,i,j-1);

        return dp[i][j]=min({a,b,c});
    }
    int almostPalindromic(string s) {

        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        solve(dp,s,0,n-1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<dp[i][j]<<" ";
                if(dp[i][j]==1 || dp[i][j]==0){
                    ans=max(ans,abs(i-j)+1);
                }
            }
            cout<<endl;
        }
        return ans;
       

        
    }
   ;
};;