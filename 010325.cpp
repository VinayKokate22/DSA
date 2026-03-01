class Solution {
public:
    int minPartitions(string n) {
        int maxv=0;
        for(auto it:n){
            maxv=max(maxv,it-'0');
        }
        return maxv;
    }
};