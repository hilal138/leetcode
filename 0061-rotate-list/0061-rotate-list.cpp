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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int len =0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len==k) return head;
        if(k>len)k=k%len;
        temp=head;
        ListNode* tail=head;
        ListNode* end=head;
        for(int i=1;i<len-k;i++){
            tail=tail->next;
        }
        for(int i=1;i<len;i++){
            end=end->next;
        }
        temp=tail->next;

        end->next=head;
        head=tail->next;
        tail->next=NULL;

        return head;
    }
};