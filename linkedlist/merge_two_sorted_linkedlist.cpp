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
    // its just like merging two sorted arrays we just add the 
    // least element among list1 and list2 and move it to the next
    // until one of them becomes empty ( reaches null ) then we 
    // directly add the rest of the remaining list 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto curr1 = list1;
        auto curr2= list2;
        if(curr1==NULL and curr2==NULL){
            return NULL;
        }
        if(curr1==NULL){
            return curr2;
        }
        else if(curr2 == NULL){
            return curr1;
        }
        ListNode* head = NULL;
        if(curr1->val < curr2->val){
            head = curr1;
            curr1=curr1->next;
        }
        else{
            head = curr2;
            curr2=curr2->next;
        }
        auto curr = head;
        while(curr1 != NULL and curr2 != NULL){
            if(curr1->val < curr2->val){
            curr->next = curr1;
            curr = curr->next;
            curr1=curr1->next;
            }
            else{
            curr->next = curr2;
            curr=curr->next;
            curr2=curr2->next;
            }
        }
        while(curr1 != NULL){
            curr->next = curr1;
            curr=curr->next;
            curr1=curr1->next;
        }
        while(curr2!= NULL){
            curr->next = curr2;
            curr=curr->next;
            curr2=curr2->next;
        }
        return head;
    }
};