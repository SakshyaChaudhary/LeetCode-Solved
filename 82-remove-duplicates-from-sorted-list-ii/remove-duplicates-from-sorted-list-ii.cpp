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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* Dummy=new ListNode(-1);
        Dummy->next=head;
        ListNode* prev=Dummy;
        ListNode* curr=Dummy->next;
        bool repeat=false;
        while(curr!=NULL){
            ListNode* next=curr->next;
            while(next!=NULL && curr->val==next->val){
                repeat=true;
                next=next->next;
            }
            if(repeat){
                prev->next=next;
                curr=next;
                repeat=false;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        head=Dummy->next;
        delete Dummy;
        return head;
        
        
    }
};