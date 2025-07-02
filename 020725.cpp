class Solution {
public:
#define ll long long
    
    int possibleStringCount(string word, int k) {



        int n = word.length();
        ll mod = 1e9+7;
        int i=0;


        if(n==0) return 0;
        if(n==k) return 1;
        if(n<k) return 0;
        vector<int> freq;

        while(i<n){
            int j=i;
            while(j<n && word[j]==word[i]){
                j++;
            }
            freq.push_back(j-i);
            i=j;
        }


        ll total=1;
        for(auto x:freq)total=(total*x)%mod ;
        if(k<freq.size()) return total; 


        vector<int> dp(k, 0);
        dp[0]=1;

        for (int it : freq) {
            vector<int> dp2(k, 0);
            long long sum = 0;
            for (int s=0;s<k;++s){
                if (s>0){
                    sum=(sum+dp[s-1])% mod;
                }
                if (s>it){
                    sum=(sum-dp[s-it-1]+mod)%mod;
                }
                dp2[s] = sum;
            }
            dp = dp2;
        }

        long long invalid = 0;
        for (int i=freq.size();i<k;++i)
            invalid=(invalid+dp[i])%mod;

        return (total-invalid+mod)%mod;



     
    }
};