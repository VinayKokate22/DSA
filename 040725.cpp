class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int addon = 0;
        while(k!=1){
            int lowerhalf = __lg(k);
            
            if((1LL<<lowerhalf)==k){
                lowerhalf--;
            }
            int op = operations[lowerhalf];

            if(op!=0){
                addon++;
            }

            k = k - (1LL<<lowerhalf);

        }

        return 'a' + addon%26 ;
    }
};