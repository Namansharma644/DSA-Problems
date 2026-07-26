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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr)
        {
           
            if(curr->val==val)
            {
                 if(curr==head)
                {
                    ListNode* temp=curr;
                    head=head->next;
                    curr=curr->next;
                    delete temp;
                }
                else
                {
                    ListNode* temp=curr;
                    prev->next=temp->next;
                    ListNode* nextNode=temp->next;
                    delete temp;
                    curr=nextNode;
                }
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};