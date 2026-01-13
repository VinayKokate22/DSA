class Solution {
public:
    bool valid(double &mid,vector<vector<int>>& squares){
        double up=0;
        double down=0;
        for(int i=0;i<squares.size();i++){
            double lowery=squares[i][1];
            double highery=squares[i][1]+squares[i][2];
            
                // cout<<lowery<<" "<<highery<<" "<<mid<<endl;
            
            if(highery<=mid){
                down+=double((double)squares[i][2]*(double)squares[i][2]);
            }
            else if(lowery>=mid){
                up+=double((double)squares[i][2]*(double)squares[i][2]);
            }
            else{
                down+=double((double)squares[i][2]*(double)(mid-lowery));
                up+=double((double)squares[i][2]*(double)(highery-mid));
            }
            // cout<<up<<" "<<down<<endl;
        }
        if(up>down)return false;
        return true;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double start=1e9;
        double end=0;
        for(int i=0;i<squares.size();i++){
            start=min(start,(double)squares[i][1]);
            end=max(end,(double)(squares[i][1]+squares[i][2]));
        }
        double mid;
        double ans;
        while(start<=end){
            mid=(start+end)/(double)2;
            // cout<<mid<<endl;
            if(valid(mid,squares)){
                ans=mid;
                end=mid-0.000001;
            }
            else start=mid+0.000001;
        }
        return ans;
    }
};