class FindSumPairs {
    vector<int>a;
    vector<int>b;
    map<int,int>hmap;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        a=nums1;
        b=nums2;
        for(auto it:b){
            hmap[it]++;
        }
        

    }
    
    void add(int index, int val) {
        hmap[b[index]]--;
        b[index]+=val;
        hmap[b[index]]++;

    }
    
    int count(int tot) {
        
        int ans=0;

        for(int i=0;i<a.size();i++){
            int val=tot-a[i];

            ans+=hmap[val];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */