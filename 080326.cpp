class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        set<int>hset;
        for(int i=0;i<nums.size();i++){
            int num=0;
            for(int j=0;j<nums[i].size();j++){
                num*=2;
                if(nums[i][j]=='1'){
                    num+=1;
                }
            }
            hset.insert(num);
        }
        for(int i=0;i<=20;i++){
            if(hset.find(i)==hset.end()){
                string ans;
                int val=i;
                while(val){
                    ans.push_back(val%2+'0');
                    val/=2;
                }
                while(ans.length()!=nums.size()){
                    ans.push_back('0');
                }
                reverse(ans.begin(),ans.end());
                return ans;
            }
        }
        return "";

    }
};