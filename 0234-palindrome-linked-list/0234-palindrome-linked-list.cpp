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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=NULL;

        while(curr!=NULL)
        {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast && fast->next)
        {
           prev=slow;
           slow=slow->next;
           fast=fast->next->next;
        }

        ListNode* tail=reverse(slow);
        prev->next=NULL;

        while(head && tail)
        {
            if(head->val != tail->val)
            {
                return false;
            }
            tail=tail->next;
            head=head->next;
        }
        return true;
    }
};