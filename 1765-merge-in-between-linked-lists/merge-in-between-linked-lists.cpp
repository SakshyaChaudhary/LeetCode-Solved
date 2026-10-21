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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2){
        ListNode* Dummy=new ListNode(-1);
        Dummy->next=list1;
        ListNode* prev=Dummy;
        ListNode* curr=Dummy->next;
        ListNode* start=NULL;
        ListNode* del=NULL;
        int count=0;
        while(curr!=NULL){
            if(count==a){
                start=curr;
                while(count!=b+1){
                    count++;
                    del=start;
                    start=start->next;
                    delete del;
                }
                break;
            }
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=list2;
        while(list2->next!=NULL){
            list2=list2->next;
        }
        list2->next=start;
        return Dummy->next;        
    }
};