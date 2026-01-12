class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            int xdiff=abs(points[i+1][0]-points[i][0]);
            int ydiff=abs(points[i+1][1]-points[i][1]);
            
            ans+=min(xdiff,ydiff)+abs(ydiff-xdiff);
        }
        return ans;
    }
};