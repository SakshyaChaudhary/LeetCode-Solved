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
    ListNode* removeElements(ListNode* head, int value){
        if(head==NULL){
            return head;
        }
        while(head->val==value){
            head=head->next;
            if(head==NULL){
                return head;
            }
        }

        ListNode* Curr=head;
        ListNode* nextNode=head->next;
        while(nextNode!=NULL){
            if(nextNode->val==value){
                Curr->next=nextNode->next;
                nextNode=nextNode->next;
            }
            else{
                Curr=nextNode;
                nextNode=nextNode->next;
            }
        }
        return head;
        
    }
};