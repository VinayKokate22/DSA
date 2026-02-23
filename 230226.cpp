class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>hset;
        string temp;
        int n=s.length();
        int i=0;
        if(k>n)return false;
        for(i=0;i<k;i++){
            temp.push_back(s[i]);
        }
        hset.insert(temp);
        while(i<n){
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            reverse(temp.begin(),temp.end());
            temp.push_back(s[i]);
            hset.insert(temp);
            i++;
        }
        if(hset.size()==pow(2,k))return true;
        return false;

    }
};