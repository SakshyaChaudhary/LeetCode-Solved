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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Dummy=new ListNode();
        int carry=0;
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* curr=Dummy;
        while(t1!=NULL || t2!=NULL){
            ListNode* node=new ListNode(0);
            int sum=0;
            if(t1==NULL){
                sum=t2->val +carry;
            }
            else if(t2==NULL){
                sum=t1->val +carry;
            }
            else{
                sum=t1->val + t2->val +carry;
            }
            carry=sum/10;
            sum=sum%10;
            node->val=sum;
            curr->next=node;
            curr=curr->next;
            if(t1 != NULL) t1 = t1->next;
            if(t2 != NULL) t2 = t2->next;
        }
        if(carry!=0){
            ListNode* node=new ListNode(0);
            node->val=carry;
            curr->next=node;
        }
        return Dummy->next;
      
    }
};