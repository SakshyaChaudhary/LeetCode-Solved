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
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead=Reverse(head);
        ListNode* curr=newHead;
        int carry=0;
        int result=0;
        while(curr!=NULL){
            result=(curr->val*2)+carry;
            curr->val=result%10;
            carry=result/10;
            curr=curr->next;
        }
        head=Reverse(newHead);
        if(carry){
            ListNode* node=new ListNode(1);
            node->next=head;
            head=node;
        }
        return head;
        
    }
    ListNode* Reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};