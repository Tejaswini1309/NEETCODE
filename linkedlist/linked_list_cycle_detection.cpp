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
// here we maintain two diff pointers fast and slow , as we keep traversing 
// if there is no loop we will encounter null at some point then we 
// return false , else if there is a loop , within the loop 
// each time we change slow and fast the distance between them increases
// by one so at some point it will be equal to the number of nodes
// in the loop so fast and slow will be equal if they are equal we return 
// true .
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow!=NULL and fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};