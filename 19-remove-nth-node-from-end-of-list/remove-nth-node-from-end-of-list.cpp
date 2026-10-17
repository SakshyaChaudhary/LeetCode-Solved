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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        int i=0;
        while(i!=n){
            //Move Fast n times
            fast=fast->next; 
            i++;
        }
        if(fast==NULL){
            //delete head
            return head->next;
        }
        while(fast->next!=NULL){
            //Move Slow Remaining times
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;        
    }
};