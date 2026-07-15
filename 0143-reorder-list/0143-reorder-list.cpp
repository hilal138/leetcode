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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head->next==NULL) return ;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        ListNode* mid= reverse(fast);

        ListNode* tempLeft=head;
        ListNode* tempRight=mid;
        ListNode* Lnxt=NULL;
        ListNode* Rnxt=NULL;
        while(tempLeft and tempRight){
            Lnxt=tempLeft->next;
            Rnxt=tempRight->next;
            tempLeft->next=tempRight;
            tempRight->next=Lnxt;
            tempLeft=Lnxt;
            tempRight=Rnxt;
        }

       // tempLeft->next=NULL;
        return ;
    }
};