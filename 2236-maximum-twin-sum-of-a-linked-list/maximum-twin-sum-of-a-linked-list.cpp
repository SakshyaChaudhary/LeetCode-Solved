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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=Reverse(slow);
        ListNode* tempA=head;
        ListNode* tempB=newHead;
        int maxSum=0;
        int currSum=0;
        while(tempB!=NULL){
            currSum=tempA->val+tempB->val;
            maxSum=max(maxSum,currSum);
            tempA=tempA->next;
            tempB=tempB->next;
        }
        Reverse(newHead);
        return maxSum;
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