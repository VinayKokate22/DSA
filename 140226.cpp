class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>prev;
        prev.push_back(double(poured));
        for(int i=1;i<=query_row;i++){
            vector<double>current(i+1,0);
            for(int j=0;j<prev.size();j++){
                if(prev[j]>1)current[j]+=(prev[j]-1)/2;
                if(prev[j]>1)current[j+1]+=(prev[j]-1)/2;
            }
            prev=current;
        }
        
        return min((double)1,prev[query_glass]);
    }
};