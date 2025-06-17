class Solution {
public:
    int binpow(int a,int b){
        int MOD=1e9+7;

        long long val=a;
        long long ans=1;

        while(b){
            if((b&1)==1){
                ans=(ans*val)%MOD;
            }
            val=(val*val)%MOD;
            b=b>>1;
        }

        return (int)ans;
    }
    long long modInverse(long long a, long long mod){
        long long res = 1;
        long long power = mod - 2;

        while (power){
            if (power & 1)
                res = res * a % mod;
            a = a * a % mod;
            power >>= 1;
        }

        return res;
    }

    int nCr(int n, int r){
        int MOD=1e9+7;
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        long long res = 1;

        for (int i = 1; i <= r; i++){
            res = res * (n - r + i) % MOD;
            res = res * modInverse(i, MOD) % MOD;
        }

        return (int)res;
    }

    int countGoodArrays(int n, int m, int k) {
        

        int MOD=1e9+7;
        int ans=(( (long long)m * binpow(m-1,n-1-k))%MOD * nCr(n-1,k) )%MOD;
        return ans;
    }
};