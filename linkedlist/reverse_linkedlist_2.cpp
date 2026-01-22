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
// here we make a reverse function whose parameters are the pointers 
// of left and right indices , this funciton reverses the given sublist
// and we update the ends after that , that is the rights next being 
// lefts previous and lefts next beings rights next 
    void rev(ListNode* prev,ListNode* l,ListNode* r){
      if(prev != NULL){
       prev->next = r;
      }
      ListNode* cu = l->next;
      prev = l;
      while(cu!=r){
            auto next = cu->next;
            cu->next = prev;
            prev = cu;
            cu = next;
      }
      l->next = r->next;
      r->next = prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
          return head;
        }
        auto l = head;
        auto r = head;
        auto curr = head;
        int i=0;
        ListNode* prev = NULL;
        while(curr!=NULL){
            if(i==left-2){
              prev = curr;
            }
            if(i==left-1){
              l = curr;
            }
            if(i==right-1){
              r = curr;
            }
            curr=curr->next;
            i++;
        }
        rev(prev,l,r);
        if(head==l){
          return r;
        }
        return head;
    }
};