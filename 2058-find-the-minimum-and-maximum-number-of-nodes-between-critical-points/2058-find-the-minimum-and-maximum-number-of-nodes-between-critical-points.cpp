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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL) return {-1,-1};
        vector<int>pos;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nxt=NULL;
        int step=1;
        while(curr->next){
            nxt=curr->next;
            step++;
            if((curr->val > nxt->val and curr->val > prev->val) or (curr->val < nxt->val and curr->val < prev->val)) {
                pos.push_back(step);
            }
            prev=curr;
            curr=nxt;
        }
        int n =pos.size();
        if(n<2) return {-1,-1};
        if(n==2) return {abs(pos[0]-pos[1]),abs(pos[0]-pos[1])};
        int Min=INT_MAX;
        int Max=pos[n-1]-pos[0];
        for(int i=0;i<pos.size()-1;i++){
            Min=min(Min,abs(pos[i]-pos[i+1]));
        }
        return {Min,Max};
    }
};