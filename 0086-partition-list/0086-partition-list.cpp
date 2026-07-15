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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* lesser = new ListNode(100);
        ListNode* greater = new ListNode(100);
        ListNode* tless=lesser;
        ListNode* tgreater=greater;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                tless->next=temp;
                temp=temp->next;
                tless=tless->next;
            }
            else{
                tgreater->next=temp;
                temp=temp->next;
                tgreater=tgreater->next;
            }
        }
        if(tless==lesser){
            tgreater->next=NULL;
            return greater->next;
        }
        if(tgreater==greater){
            tless->next=NULL;
            return lesser->next;
        }
        
        tless->next=greater->next;
        tgreater->next=NULL;
        return lesser->next;
    }
};