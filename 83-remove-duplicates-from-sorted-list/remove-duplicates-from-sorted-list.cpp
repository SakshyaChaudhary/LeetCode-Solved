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
        if(head==NULL){
            return head;
        }
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* del=NULL;
        while(second!=NULL){
            if(first->val!=second->val){
                first=first->next;
                second=second->next;
            }
            else{
                del=second;
                second=second->next;
                first->next=second;
                delete del;
            }            
        }
        return head;
    }
};