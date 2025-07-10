class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
        vector<int>v;
        int startlimit=0;
        int endlimit=startTime[0];

        v.push_back(endlimit-startlimit);

        int i=1;
        int n=startTime.size();

        while(i<n){
            startlimit=endTime[i-1];
            endlimit=startTime[i];

            v.push_back(endlimit-startlimit);
            i++;
        }

        endlimit=endTime.back();
        v.push_back(eventTime-endlimit);

        // 4 2 3 1 2
        vector<int>left;
        vector<int>right(v.size(),0);

        int maxv=0;
        for(int i=0;i<v.size();i++){
            maxv=max(maxv,v[i]);
            left.push_back(maxv);
        }
        maxv=0;
        for(int i=v.size()-1;i>=0;i--){
            maxv=max(maxv,v[i]);
            right[i]=maxv;
        }

        int ans=0;

        for(int i=0;i+1<v.size();i++){
            int val=v[i]+v[i+1];
            int size=endTime[i]-startTime[i];

            int leftmax=0;
            if(i-1>=0)leftmax=left[i-1];
            int rightmax=0;
            if(i+2<v.size()){
                rightmax=right[i+2];
            }
            if(leftmax>=size || rightmax>=size){
                val+=size;
            }
            ans=max(ans,val);

        }
        return ans;


    }
};