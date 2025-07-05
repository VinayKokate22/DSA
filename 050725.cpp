class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>count(501,0);
        for(auto it:arr){
            count[it]++;
        }
        int ans=-1;
        for(int i=1;i<count.size();i++){
            if(i==count[i]){
                ans=i;
            }
            
        }
        return ans;


    }
};