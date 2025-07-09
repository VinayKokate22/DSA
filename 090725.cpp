class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        int i=1;
        int endlimit=startTime[0];
        int startlimit=0;

        int count=0;
        int sum=0;
        int n=startTime.size();
        vector<int>v;
        
        sum+=(endlimit-startlimit);
        v.push_back(sum);
        

        while(i<n){
            startlimit=endTime[i-1];
            endlimit=startTime[i];
            sum+=(endlimit-startlimit);
            v.push_back(sum);
            i++;
        }
        endlimit=endTime.back();
        sum+=(eventTime-endlimit);
        v.push_back(sum);
        int ans=0;
        for(int i=0;i+k<v.size();i++){
            int prev=0;
            if(i-1>=0)prev=v[i-1];
            ans=max(ans,v[i+k]-prev);
        }
        return ans;

    }
};