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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
           while(temp->next != NULL && temp->val==temp->next->val)
           {
               ListNode* deletedNode=temp->next;
               temp->next=temp->next->next;
               delete deletedNode;
           }

           temp=temp->next;
        }
        return head;
    }
};