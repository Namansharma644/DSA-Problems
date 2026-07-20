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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (head == NULL || left == right)
            return head;

           ListNode* temp=head;
           ListNode* prev=NULL;
           ListNode* nextNode=NULL;
           ListNode* front=NULL;
           ListNode* Back=NULL;
           ListNode* l=NULL;
           ListNode* r=NULL;

           int i=0;

           while(i<right)
           {
             if(i==left-2){
                front=temp;
             }
             if(i==left-1){
                l=temp;
                prev=NULL;
             }
             if(i==right-1){
                r=temp;
             }

             if(i>=left-1)
             {
                nextNode=temp->next;
                temp->next=prev;
                prev=temp;
                temp=nextNode;
             }
             else
             {
                prev=temp;
                temp=temp->next;
             }
            i++;
           }

           if(r->next!=NULL)
           {
             l->next=temp;
           }

           if(l!=head)
           {
              front->next=r;
           }
          
          return (left==1) ? prev : head;
    }
};