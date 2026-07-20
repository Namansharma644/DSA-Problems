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
        int count=0;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=len(head);
        int groups=n/k;
        ListNode* prevHead=NULL;
        ListNode* currHead=head;
        ListNode* ansNode=NULL;

        for(int i=0; i<groups; i++)
        {
            ListNode* prev=NULL;
            ListNode* curr=currHead;
            ListNode* nextNode=NULL;
            int count=0;

            while(count<k)
            {
                nextNode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextNode;
                count++;
            }

            if(prevHead==NULL)
            {
                ansNode=prev;
            }
            else
            {
               prevHead->next=prev;
            }
            prevHead=currHead;
            currHead=curr;
        }

        prevHead->next=currHead;
        return ansNode;
    }
};