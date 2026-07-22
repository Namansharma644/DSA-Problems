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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        ListNode* odd=new  ListNode(-1);
        ListNode* even=new  ListNode(-1);
        ListNode* oddP=odd;
        ListNode* evenP=even;

        ListNode* temp=head;
        bool isEven=false;

        while(temp!=NULL)
        {
            if(isEven)
            {
               evenP->next=temp;
               evenP=evenP->next;
            }
            else
            {
               oddP->next=temp;
               oddP=oddP->next;
            }
            isEven=!isEven;
            temp=temp->next;
        }

        oddP->next=even->next;
        evenP->next=NULL;
        return odd->next;
    }
};