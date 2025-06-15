class Solution {
public:
    int maxDiff(int num) {
        int maxv=INT_MIN;
        int minv=INT_MAX;
        string s=to_string(num);
        for(int i=0;i<=9;i++){
            string str=s;
            for(int j=0;j<str.length();j++){
                if((str[j]-'0')==i){
                    str[j]='9';
                }
            }
            maxv=max(maxv,stoi(str));
            str=s;
            string str2=s;
            for(int j=0;j<str.length();j++){
                if((str[j]-'0')==i){
                    str[j]='0';
                }
                if((str2[j]-'0')==i){
                    str2[j]='1';
                }
            }
            if(str[0]!='0'){
                minv=min(minv,stoi(str));
            }
            minv=min(minv,stoi(str2));

        } 
        return maxv-minv;
    }
};