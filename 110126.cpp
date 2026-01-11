class Solution {
public:
    int solve(vector<int>&height){
        stack<pair<int,int>>stk;
        vector<int>smaller_to_right;
        vector<int>smaller_to_left;

        for(int i=height.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top().first>=height[i]){
                stk.pop();
            }
            if(stk.empty()){
                smaller_to_right.push_back(height.size());
            }
            else smaller_to_right.push_back(stk.top().second);
            stk.push({height[i],i});
        }
        reverse(smaller_to_right.begin(),smaller_to_right.end());

        while(stk.size()){
            stk.pop();
        }

        for(int i=0;i<height.size();i++){
            while(!stk.empty() && stk.top().first>=height[i]){
                stk.pop();
            }
            if(stk.empty()){
                smaller_to_left.push_back(-1);
            }
            else smaller_to_left.push_back(stk.top().second);
            stk.push({height[i],i});
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans=max(ans,height[i]*((smaller_to_right[i]-smaller_to_left[i])-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            ans=max(ans,solve(height));
        }
        return ans;
    }
};