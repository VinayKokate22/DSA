class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int>row;
        vector<int>col;
        for(int i=0;i<mat.size();i++){
            int count=0;

            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            row.push_back(count);
        }

        for(int j=0;j<mat[0].size();j++){
            int count=0;

            for(int i=0;i<mat.size();i++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            col.push_back(count);
        }
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};