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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* evenLL = new ListNode(100);
        ListNode* oddLL = new ListNode(0);
        ListNode* tempodd=head;
        ListNode* tempeven=head->next;
        ListNode* t1=oddLL;
        ListNode* t2=evenLL;
        while(tempodd){
            t1->next=tempodd;
            t2->next=tempeven;
            if(tempeven==NULL) tempodd=tempeven;
            else  tempodd=tempeven->next;
            if(tempodd==NULL) tempeven=tempodd;
            else tempeven=tempodd->next;
            t1=t1->next;
            t2=t2->next;
        }
            t1->next=evenLL->next;
            return oddLL->next;
    }
};