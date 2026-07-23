/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode *head)
    {
        int size=0;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        return size;
    }
    ListNode*  collide(ListNode *t1, ListNode *t2,int d)
    {
        while(d--)
        {
            t1=t1->next;
        }

        while(t1!=t2)
        {
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
        {
            return NULL;
        }
        int n1=len(headA);
        int n2=len(headB);

        if(n1>n2)
        {
            return collide(headA,headB,n1-n2);
        }
        return collide(headB,headA,n2-n1);
    }
};