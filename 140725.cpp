/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s;
        while(head){
            s.push_back(head->val+'0');
            head=head->next;
        }
        int ans=0;
        int val=1;

        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=val;
            }
            val=val*2;
        }
        return ans;
    }
};