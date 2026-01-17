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
// since the max size of linkedlist is 1000 as per given limits 
// we maintain a hash where we store the pointers of ith location 
// at ith index , and using two pointers i and j ( one points 
// to the beginning of the hash and one points to the place where
// the last element was stored ) we add them alternatively to the 
// linked list ( replace the previous ones ) , we do it until the below
// conditions are met , but it will pause at i ==j when the 
// lenght is odd so we must add that separately also do not forget to 
// move to the next node after adding and adding null at last 
    void reorderList(ListNode* head) {
        vector<ListNode*>v(1000,NULL);
        auto curr = head;
        int l=0;
        while(curr!=NULL){
            v[l]=curr;
            l++;
            curr=curr->next;
        }
        if(l==1){
            return;
        }
        curr = head;
        int j = l-1;
        int i=1;
        while(i<j){
            curr->next = v[j];
            j--;
            curr=curr->next;
            curr->next=v[i];
            i++;
            curr=curr->next;
        }
        if(i==j){
            curr->next=v[i];
            curr=curr->next;
        }
        curr->next=NULL;
    }
};
