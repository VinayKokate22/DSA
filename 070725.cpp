class Solution {
public:
    int findnext(int val,vector<int>&dist){
        if(val==dist[val]){
            return val;
        }
        return dist[val]=findnext(dist[val],dist);
    }
    int maxEvents(vector<vector<int>>& e) {
        
        sort(e.begin(),e.end(),[](auto a,auto b){
            return a[1]<b[1];
        });

        vector<int>dist(1e5+2,0);
        for(int i=0;i<=1e5+1;i++){
            dist[i]=i;
        }
        int ans=0;
        for(auto it:e){
            int start=it[0];
            int end=it[1];

            int day=findnext(start,dist);
            if(day<=end){
                ans++;
                dist[day]=findnext(day+1,dist);
            }
        }
        return ans;

    }
};