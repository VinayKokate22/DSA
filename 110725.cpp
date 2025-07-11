

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>> >pq;
        priority_queue<long long,vector<long long>,greater<long long>>room;

        sort(meetings.begin(),meetings.end());

        vector<long long>count(n,0);
        vector<long long>endtime(n,0);
        for(long long i=0;i<n;i++){
            room.push(i);
        }
        long long i=0;
        
        while(i<meetings.size()){
            if(pq.size()>0){
                long long val=(long long)meetings[i][0];
                while(!pq.empty() &&  pq.top().first<=val){
                    long long room_no=pq.top().second;
                    long long timelimit=pq.top().first;
                    endtime[room_no]=timelimit;
                    room.push(room_no);
                    pq.pop();
                }
            }
            if(room.size()==0){
                long long val=pq.top().first;
                while(!pq.empty() &&  pq.top().first<=val){
                    long long room_no=pq.top().second;
                    long long timelimit=pq.top().first;
                    endtime[room_no]=timelimit;
                    room.push(room_no);
                    pq.pop();
                }
            }
            if(room.size()>0){
                long long room_no=room.top();
                room.pop();
                count[room_no]++;
                long long meetingtime=(long long)meetings[i][1]-(long long)meetings[i][0];
                pq.push( {max((long long)meetings[i][0],endtime[room_no])+meetingtime,room_no} );
                // cout<<room_no<<" "<<max((long long)meetings[i][0],endtime[room_no])+meetingtime<<endl;
                i++;
            }
            // cout<<"count is :: ";
            // for(auto it:count){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            // for(auto it:endtime){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
        }
        long long ans=0;
        long long value=0;
        for(long long i=0;i<n;i++){
            if(count[i]>value){
                value=count[i];
                ans=i;
            }
        }
        return ans;
    }
};