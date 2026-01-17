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
    // since the size of the linked list is too high that is almost 100
    // we cannot convert it to numbers add then input it into the list
    // so we add them individually , and maintain an other variable 
    // carry to store the carry in it and add it in the next element 
       int carry =0;
       auto a = new ListNode((l1->val+l2->val)%10);
       auto curr1 = l1->next;
       auto curr2 = l2->next;
       carry = (l1->val+l2->val)/10;
       auto curr = a;
       while(curr1 != NULL and curr2 != NULL){
            curr->next =new ListNode((curr1->val + curr2->val+carry)%10);
            carry = (curr1->val + curr2->val+carry)/10;
            curr1=curr1->next;
            curr2=curr2->next;   
            curr=curr->next;                   
       }
        while(curr1 != NULL){
            curr->next =new ListNode((curr1->val+carry)%10);
            carry = (curr1->val + carry)/10;
            curr1=curr1->next;
            curr=curr->next;
        }
        while(curr2 != NULL){
            curr->next =new ListNode((curr2->val+carry)%10);
            carry = (curr2->val + carry)/10;
            curr2=curr2->next;
            curr=curr->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
            curr=curr->next;
            curr->next = NULL;
        }
        ListNode* ptr = a;
        return ptr;
    }
};