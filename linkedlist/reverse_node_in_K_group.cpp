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
// here we first construct a helper function rev , unlike 
// other rev this has a additional parameter preve since here 
// our start isnt always the head , so we set preve next each time
// separately , in our original fn loop we maintain these variables 
// by checking when the count reaches a multiple of k , start
// initially would be head and would later change to curr next at a point 
// before reversing , end would be the curr elements , preve
// initially is null but next after rev it should become 
// the tail of the prev reversed group that is start after reversing
// hence we update preve to start , if there exits atleast
// one such group the head will change hence when c/k==1 you change
// head to end 
    void rev(ListNode* start,ListNode* end,ListNode* preve){
        ListNode*curr=start;
        auto next = curr->next;
        curr->next = end->next;
        if(preve != NULL){
        preve->next=end;
        }
        auto prev = curr;
        curr = next;
        while(curr!=end){
            next = curr->next;
            curr->next = prev;
            prev =curr;
            curr=next;
        }
        curr->next = prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        int c=0;
        auto curr = head;
        auto start = head;
        auto end= head;
        ListNode* preve = NULL;
        while(curr!=NULL){
            c++;
            auto next = curr->next;
            if(c%k==0){
                if(c/k==1){
                    head = curr;
                }
                rev(start,curr,preve);
                preve=start;
                start = next;
            }
            curr = next;
        }
        return head;
    }
};