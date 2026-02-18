class Solution {
public:
    void updateTree(vector<int>&segmentTree,int index,int i,int left,int right){
        if(left==right){
            segmentTree[i]=1;
            return ;
        }
        int mid=(left+right)/2;
        if(index<=mid)updateTree(segmentTree,index,2*i+1,left,mid);
        else updateTree(segmentTree,index,2*i+2,mid+1,right);

        segmentTree[i]=segmentTree[i*2+1]+segmentTree[2*i+2];
        return;
    }
    int solve(vector<int>&segmentTree,int i,int left,int right,int l,int r){
        if(left>r || right<l)return 0;
        if(left>=l && right<=r)return segmentTree[i];

        int mid=(left+right)/2;
        return solve(segmentTree,2*i+1,left,mid,l,r)+solve(segmentTree,2*i+2,mid+1,right,l,r);
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>segmentTree(4*n,0);
        map<int,int>hmap;
        for(int i=0;i<nums2.size();i++){
            hmap[nums2[i]]=i;
        }
        long long ans=0;
        for(int i=0;i<nums1.size();i++){
            updateTree(segmentTree,hmap[nums1[i]],0,0,n-1);
            int leftcommon=solve(segmentTree,0,0,n-1,0,hmap[nums1[i]]-1);
            int leftnon=(i-leftcommon);
            // cout<<leftcommon<<" "<<leftnon<<endl;
            int rightcommon=(n-1-hmap[nums1[i]]-leftnon);
            ans=ans+1LL*leftcommon*1LL*rightcommon;
        }
        return ans;
    }
};;