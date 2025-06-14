class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        int maxv=INT_MIN;
        int minv=INT_MAX;
        for(int i=0;i<=9;i++){
            string str=s;
            string str2=s;
            for(int k=0;k<str.length();k++){
                if((s[k]-'0')==i){
                    str[k]='9';
                    str2[k]='0';
                }
            }
            maxv=max(maxv,stoi(str));
            minv=min(minv,stoi(str2));
        }
        return maxv-minv;
    }
};