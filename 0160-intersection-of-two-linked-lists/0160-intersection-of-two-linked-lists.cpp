/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA= headA;
        ListNode* tempB= headB;
        int lenA=0;
        int lenB=0;
        while(tempA){
            lenA++;
            tempA=tempA->next;
        }
        while(tempB){
            lenB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;

        if(lenA>=lenB){
            int i=1;
            while(i<=(lenA-lenB)) {
                tempA=tempA->next;
                i++;
            }
        }
        else{
            int i=1;
            while(i<=(lenB-lenA)) {
                tempB=tempB->next;
                i++;
            }
        }
        while(tempA){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};