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
// first we calculate the length of the linked list and find the index
// of the nth element from the end , then we traverse till the n-1th element
// and delete its next element by updating the curr next to the next of 
// the element that has to be deleted , for all cases expect the case
// where the head is being deleted the head remains the same in the 
// case where we delete the head we must update the head 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=1;
        auto curr = head;
        while(curr->next!=NULL){
            curr=curr->next;
            length++;
        }
        int p = length - n;
        if(p==0){
            head = head->next;
            return head;
        }
        p-=1;
        curr = head;
        while(p){
            curr = curr->next;
            p-=1;
        }
        curr->next = curr->next->next;
        return head;
    }
};