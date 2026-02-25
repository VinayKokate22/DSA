class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // sort(arr.begin(),arr.end(),[]{
        //     return a>b;
        // })
        sort(arr.begin(),arr.end(),[](auto a,auto b){
            int val1=0;
            int val2=0;
            int p=a;
            int q=b;
            while(p){
                if(p%2)val1++;
                p/=2;
            }
            while(q){
                if(q%2)val2++;
                q/=2;
            }
            if(val1==val2){
                return a<b;
            }
            return val1<val2;
            // return a<b;
        });
        return arr;
    }
};