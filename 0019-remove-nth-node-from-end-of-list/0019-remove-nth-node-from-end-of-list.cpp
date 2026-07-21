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
    int len(ListNode* head)
    {
        int size=0;
        while(head!=NULL)
        {
            size++;
            head=head->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L=len(head);
        if(L==n)
        {
            ListNode* temp=head->next;
            delete head;
            return temp;
        }
        int pos=L-n+1;
        int count=1;
        ListNode* prev=head;
        ListNode* temp=head;
        while(count<pos)
        {
           prev=temp;
           temp=temp->next;
           count++;
        }

        prev->next=temp->next;
        delete temp;
        return head;
    }
};