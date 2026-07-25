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
        ListNode* fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* last=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        ListNode* mid=findMid(head);
        ListNode* curr=head;
        ListNode* rev=reverse(mid);

        while(rev->next)
        {
            ListNode* tempCurr=curr->next;
            curr->next=rev;
            ListNode* tempRev=rev->next;
            rev->next=tempCurr;
            rev=tempRev;
            curr=tempCurr;
        }
    }
};