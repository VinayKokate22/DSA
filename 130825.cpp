class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans=0;

        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=0;
        int j=0;
        
        int n=players.size();
        int m=trainers.size();

        while(i<n && j<m){
            if(trainers[j]>=players[i]){
                ans++;
                j++;
                i++;
            }
            else {
                j++;
            }
        }
        return ans;

    }
};