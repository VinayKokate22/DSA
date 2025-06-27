class Solution {
public:

    bool valid(string &a,int &k,string &b){
        int count=0;
        int index=0;
        int i=0;
        while(i<b.length()){
            if(b[i]==a[index]){
                i++;
                index++;
                if(index==a.length()){
                    count++;
                    index=0;
                }
            }
            else{
                i++;
            }
        }

        if(count>=k)return true;
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        
        

        int n=s.length();
        set<char>hset;
        for(int i=0;i<n;i++){
            hset.insert(s[i]);
        }
        int msk=0;
        for(auto it:hset){
            int val=it-'a';
            msk=msk|(1<<val);
        }

        queue<pair<string,int>>q;
        q.push({"",msk});
        string ans="";
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            string a=front.first;
            int mask=front.second;


            for(int i=0;i<26;i++){
                if ((mask & (1<<i))==0)
                {
                    continue;
                }
                string str=a;
                str.push_back(i+'a');

                if(valid(str,k,s)){
                    q.push({str,mask});
                }
                else{
                    mask=(mask & ~(1<<i));
                }

            }
            if(a.length()>=ans.length()){
                ans=a;
            }
        }
        return ans;

    }
};