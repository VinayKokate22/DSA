class Solution {
public:
    bool valid(vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&grid,int i_index,int j_index,int &k){
        int n=grid1.size();
        int m=grid1[0].size();
        if(i_index+k>n)return false;
        if(j_index+k>m)return false;

        int val=-1;
        for(int i=i_index;i<i_index+k;i++){
            int left_sum=0;
            if(j_index-1>=0)left_sum=grid1[i][j_index-1];
            int sum=grid1[i][j_index+k-1]-left_sum;
            if(val==-1)val=sum;
            // cout<<k<<" "<<sum<<endl;
            if(sum!=val)return false;
        }
        val=-1;
        for(int j=j_index;j<j_index+k;j++){
            int top_sum=0;
            if(i_index-1>=0)top_sum=grid2[i_index-1][j];
            int sum=grid2[i_index+k-1][j]-top_sum;
            if(val==-1)val=sum;
            // cout<<k<<" * "<<sum<<endl;
            if(sum!=val)return false;
        }
        int i=i_index;
        int j=j_index;
        int sum=0;
        while(i<i_index+k){
            sum+=grid[i][j];
            i++;
            j++;
        }
        if(sum!=val)return false;
        i=i_index;
        j=j_index+k-1;
        sum=0;
        while(i<i_index+k){
            sum+=grid[i][j];
            i++;
            j--;
        }
        if(sum!=val)return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=1;
        int n=grid.size();
        int m=grid[0].size();
        int dimention=min(n,m);

        vector<vector<int>>grid1=grid;
        vector<vector<int>>grid2=grid;

        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
                grid1[i][j]=sum;
            }
            sum=0;
        }

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
                grid2[i][j]=sum;
            }
            sum=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=ans;k<=dimention;k++){
                    // cout<<"k is "<<k<<" "<<i<<" "<<j<<endl;
                    if(valid(grid1,grid2,grid,i,j,k)){
                        ans=k;
                    }
                }
            }
        }
        return ans;
    }
};