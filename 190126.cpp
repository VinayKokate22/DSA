class Solution {
public:
    bool valid(vector<vector<int>>&mat,int& i_index,int& j_index,int& k,int & threshold){
        int bottomright_i=i_index+k-1;
        int bottomright_j=j_index+k-1;

        if(bottomright_i>=mat.size() || bottomright_j>=mat[0].size()){
            return false;
        }
        int a=0,b=0,c=0;

        if(j_index-1>=0){
            a=mat[bottomright_i][j_index-1];
        }
        if(i_index-1>=0){
            b=mat[i_index-1][bottomright_j];
        }
        if( j_index-1>=0 && i_index-1>=0){
            c=mat[i_index-1][j_index-1];
        }
        int sum=mat[bottomright_i][bottomright_j]-a-b+c;
        if(sum<=threshold)return true;
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans=0;
        int m=mat.size();
        int n=mat[0].size();
        int dimention=min(m,n);

        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
                mat[i][j]=sum;
            }
            sum=0;
        }
        sum=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                sum+=mat[i][j];
                mat[i][j]=sum;
            }
            sum=0;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=ans;k<=dimention;k++){
                    if(valid(mat,i,j,k,threshold)){
                        ans=k;
                    }
                }
            }
        }
        return ans;
    }
};