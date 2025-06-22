class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while(s.length()%k!=0){
            s.push_back(fill);
        }

        vector<string>ans;

        for(int i=0;i<s.length();i+=k){
            ans.push_back(s.substr(i,k));
        }
        return ans;
    }
};