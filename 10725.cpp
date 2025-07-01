class Solution {
public:
    int possibleStringCount(string word) {
        
        int ans=1;
        int i=0;
        int count=0;
        while(i<word.size()){
            if(i>0 && word[i]==word[i-1]){
                count++;
            }
            else{
                ans+=count;
                count=0;
            }
            i++;
        }
        ans+=count;
        return ans;
    }
};