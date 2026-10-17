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
        int count=0;
        while(true){
            if(fast==NULL){
                count=count*2;
                break;
            }
            if(fast->next==NULL){
                count=(count*2)+1;
                break;
            }
            count++;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(n>count){
            return head;
        }
        if(n==count){
            return head->next;
        }
        int front=count-n+1;
        int i=1;
        slow=NULL;
        fast=head;
        while(fast!=NULL){
            if(i==front){
                slow->next=slow->next->next;
                delete fast;
                break;
            }
            i++;
            slow=fast;
            fast=fast->next;
        }
        return head;
        
    }
};