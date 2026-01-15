class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxrow=1;
        int count=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1){
                count++;
                maxrow=max(maxrow,count);
            }
            else count=1;
        }
        int maxcol=1;
        count=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1){
                count++;
                maxcol=max(maxcol,count);
            }
            else count=1;
        }
        int val=min(maxrow,maxcol)+1;
        return val*val;
    }
};