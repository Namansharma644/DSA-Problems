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
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge2List(ListNode* list1,ListNode* list2)
    {
       if(!list1) return list2;
       if(!list2) return list1;

       ListNode* head=new ListNode(-1);
       ListNode* temp=head;
       while(list1 && list2)
       {
          if(list1->val<list2->val)
          {
             temp->next=list1;
             temp=temp->next;
             list1=list1->next;
          }
          else
          {
             temp->next=list2;
             temp=temp->next;
             list2=list2->next;
          }
       }
       temp->next=(list1) ?  list1 : list2;
       return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* mid=findMid(head);
        ListNode* leftHead=head;
        ListNode* rightHead=mid->next;
        mid->next=NULL;

        ListNode* l1=sortList(leftHead);
        ListNode* l2=sortList(rightHead);

        return merge2List(l1,l2);
    }
};