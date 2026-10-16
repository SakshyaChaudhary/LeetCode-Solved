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
        ListNode* del=NULL;
        while(head->val==value){
            del=head;
            head=head->next;
            delete del;
            if(head==NULL){
                return head;
            }
        }

        ListNode* Curr=head;
        ListNode* nextNode=head->next;
        while(nextNode!=NULL){
            if(nextNode->val==value){
                del=nextNode;
                Curr->next=nextNode->next;
                nextNode=nextNode->next;
                delete del;
            }
            else{
                Curr=nextNode;
                nextNode=nextNode->next;
            }
        }
        return head;
        
    }
};