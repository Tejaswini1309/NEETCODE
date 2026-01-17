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
// we have to reverse the linked list hence for every node we have 
// to make its previous its next , so we always need to keep track of 
// its previous , when we update its next , its original next will 
// be lost so we also need to store that , hence each time we store its next 
// before updating which is what we update out curr to , and also store
// the current curr as previous 
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        if(head == NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = NULL;
        while(curr!=NULL){
            auto Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
};
