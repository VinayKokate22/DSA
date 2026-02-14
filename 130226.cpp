class Solution {
public:
    int findsingle(string &s,char c){
        int count=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==c)count++;
            else count=0;
            ans=max(ans,count);
        }
        return ans;
    }
    int finddouble(string &v,char  a, char b){
        int count=0;
        map<int,int>hmap;
        hmap[0]=-1;
        int val=0;
        for(int i=0;i<v.length();i++){
            if(v[i]==a)count++;
            else if(v[i]==b) count--;
            else{
                hmap.clear();
                hmap[0]=i;
                count=0;
            }
            if(hmap.find(count)!=hmap.end()){
                val=max(val,i-hmap[count]);
            }
            else{
                hmap[count]=i;
            }
        }
        return val;
    }
    int findthree(string &v){
        int count1=0;
        int count2=0;
        map<pair<int,int>,int>hmap;
        hmap[{0,0}]=-1;
        int val=0;
        for(int i=0;i<v.length();i++){
            if(v[i]=='a'){
                count1++;
                count2++;
            }
            else if(v[i]=='b'){
                count1--;
            }
            else count2--;
            if(hmap.find({count1,count2})!=hmap.end()){
                val=max(val,i-hmap[{count1,count2}]);
            }
            else{
                hmap[{count1,count2}]=i;
            }

        }
        return val;
    }
    int longestBalanced(string v) { 
        int val=0;
        val=max(val,findsingle(v,'a'));
        val=max(val,findsingle(v,'b'));
        val=max(val,findsingle(v,'c'));

        val=max(val,finddouble(v,'a','b'));
        val=max(val,finddouble(v,'a','c'));
        val=max(val,finddouble(v,'b','c'));

        val=max(val,findthree(v));

        return val;
    }
};