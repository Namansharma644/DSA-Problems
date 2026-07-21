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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* smallHead=NULL;
        ListNode* largeHead=NULL;
        ListNode* smallp=NULL;
        ListNode* largep=NULL;

        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                ListNode* newNode=new ListNode(temp->val);
                if(smallHead==NULL)
                {
                    smallHead=smallp=newNode;
                }
                else
                {
                    smallp->next=newNode;
                    smallp=newNode;
                }
            }
            else
            {
                ListNode* newNode=new ListNode(temp->val);
                if(largeHead==NULL)
                {
                  largeHead=largep=newNode;
                }
                else
                {
                  largep->next=newNode;
                  largep=newNode;
                }
            }
            temp=temp->next;

        }
            if(smallHead == NULL)
                    return largeHead;

            smallp->next=largeHead;
            if(largep!=NULL)
            {
                largep->next=NULL;
            }
            return smallHead;
    }
};