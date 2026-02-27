class Solution {
public:
    int numSteps(string s) {
        int carry=0;
        int i=s.length()-1;
        int ans=0;
        while(i){
            if(s[i]=='1'){
                if(carry==1){
                    ans++;
                }
                else{
                    carry=1;
                    ans+=2;
                }
            }
            else{
                if(carry==1){
                    carry=1;
                    ans+=2;
                }
                else{
                    ans+=1;
                }
            }
            i--;
        }
        if(carry)ans++;
        return ans;;
    }
};