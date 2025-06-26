class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long currval=0;
        long long val=1;

        vector<int>pre;
        int count = 0;
        int n = s.length();
        pre.push_back(0);
        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                count+=1;
            }
            pre.push_back(count);
        }

        int ans=0;
        for(int i=n-1;i>=0;i--) {

            if(s[i]=='1')currval+=val;
            if(currval>k)break;
            ans=max(ans,(n-i)+pre[i]);
            val=2*val;
            if(val>1e15 )break;
        }
        return ans;
    }
};