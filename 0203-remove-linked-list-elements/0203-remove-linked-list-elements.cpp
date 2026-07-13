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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode* temp=head;
        ListNode* dummy = new ListNode(100);
        ListNode* temp2= dummy;
        while(temp){
            if(temp->val != val){
                temp2->next=temp;
                temp=temp->next;
                temp2=temp2->next;
            }
            else{
                temp=temp->next;
            }
        }
         temp2->next=NULL;
        return dummy->next;
    }
};