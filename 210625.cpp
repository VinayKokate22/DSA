class Solution {
public:
    int minimumDeletions(string word, int k) {
        
        vector<int>v(26,0);
        for(auto it:word ){
            v[it-'a']++;
        }
        sort(v.begin(),v.end());
        int n=word.length();
        int ans=INT_MAX;
        int i=0;
        int j=0;
        int leftsum=0;  
        while(v[i]==0)i++; 
           
        while(j<v.size()){
            
            while(v[j]-v[i]>k){

                ans=min(ans, n - ( leftsum +((v[i]+k)*((int)v.size()-j))) );
                leftsum=leftsum-v[i];
                i++;
            }
            leftsum+=v[j];
            j++;
        }
        ans=min(ans,n-(leftsum));

        if(ans==INT_MAX)return 0;

        return ans;



            
    }
};