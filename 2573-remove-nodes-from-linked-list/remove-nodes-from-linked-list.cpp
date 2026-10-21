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
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead=Reverse(head);
        ListNode* del=NULL;
        ListNode* curr=newHead->next;
        ListNode* Largest=newHead;
        while(curr!=NULL){
            if(curr->val<Largest->val){
                del=curr;
                Largest->next=curr->next;
                curr=curr->next;
                // delete del;
            }
            else{
                Largest=curr;
                curr=curr->next;
            }
        }
        head=Reverse(newHead);
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