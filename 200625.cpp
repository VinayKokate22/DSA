class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int>direction(4,0);

        int n=s.length();
        int x=0;
        int y=0;
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='W'){
                direction[2]++;
                x--;
            }
            else if(s[i]=='N'){
                direction[0]++;
                y++;
            }
            else if(s[i]=='S'){
                direction[1]++;
                y--;
            }
            else {
                direction[3]++;
                x++;
            }
            
            int curr=abs(x)+abs(y);
            int newk=k;


            int updown=min(direction[0] ,direction[1]);
            int rightways=min(direction[2],direction[3]);

            int maxv=max(updown,rightways);

            curr=curr+2*min(maxv,newk);
            newk=newk-min(maxv,newk);

            int minv=min(updown,rightways);

            curr=curr+2*min(minv,newk);
            ans=max(ans,curr);
        }

        return ans;



    }
};