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
// to solve this we create a helper function merge using which we
// iteratively we merge each list in lists with its next one assuming
// x as size of the linked list in lists , we merge k lists 
// for each merge the complexity is the sum of lengths of the 
// lists involved 
    ListNode* merge(ListNode* h1 , ListNode* h2){
        ListNode* curr1 = h1;
        ListNode* curr2 = h2;
        if(curr1==NULL and curr2==NULL){
            return NULL;
        }
        else if(curr1==NULL){
            return curr2;
        }
        else if(curr2==NULL){
            return curr1;
        }
        ListNode* head=NULL;
        if(curr1->val <= curr2->val){
             head = curr1;
            curr1=curr1->next;
        }
        else{
             head = curr2;
            curr2=curr2->next;
        }
        ListNode* curr = head;
        while(curr1!=NULL and curr2!=NULL){
            if(curr1->val<=curr2->val){
                curr->next = curr1;
                curr=curr->next;
                curr1=curr1->next;
            }
            else{
                curr->next = curr2;
                curr=curr->next;
                curr2=curr2->next;
            }
        }
        while(curr1!=NULL){
            curr->next = curr1;
            curr=curr->next;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            curr->next = curr2;
            curr=curr->next;
            curr2=curr2->next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0){
            return NULL;
        }
        if(n==1){
            return lists[0];
        }
        int i=0;
        ListNode* h=lists[0];
        while(i<n-1){
            h = merge(lists[i],lists[i+1]);
            lists[i+1]=h;
            i++;
        }
        return h;
    }
};