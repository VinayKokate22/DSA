class Solution {
public:
    string solve(string &s){
        string str;
        for(int i=0;i<s.length();i++){
            str.push_back(((s[i]-'a'+1)%26)+'a');
        }
        return str;
    }
    char kthCharacter(int k) {
        string s="a";

        while(s.length()<k){
            string str=solve(s);
            s=s+str;
        }
        return s[k-1];
    }
};