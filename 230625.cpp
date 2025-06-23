class Solution {
public:
    bool convert(long long a,int &k){
        string s;

        while(a)
        {
            s.push_back(a%k + '0');
            a=a/k;
        }

        int i=0;
        int j=s.length()-1;

        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

   
    long long add(long long val,int odd){
        long long num=val;

        if(odd==1){
            num=num/10;
        }
        while(num){
            val=val*10+num%10;
            num=num/10;
        }
        return val;
    }
    
    long long kMirror(int k, int n) {
        int count=0;
        long long sum=0;
        for(long long i=1; ;i*=10){

            for(long long j=i;j<i*10;j++){
                long long b=add(1LL*j,1);
                if(convert(b,k))
                {
                    count++;
                    sum+=b;
                    if(count==n)return sum;
                }

            }
             for(long long j=i;j<i*10;j++){
                long long a=add(1LL*j,0);
                if(convert(a,k))
                {
                    count++;
                    sum+=a;
                    if(count==n)return sum;
                }
            }
        }
        return -1;

        
    }
};