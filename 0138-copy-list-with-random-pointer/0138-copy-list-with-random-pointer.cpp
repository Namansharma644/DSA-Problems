/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*, Node*>m;

        Node* prev=NULL;
        Node* curr=head;
        Node* newHead=NULL;

        while(curr)
        {
            Node* newNode=new Node(curr->val);
            m[curr]=newNode;
            if(prev==NULL)
            {
                newHead=newNode;
                prev=newHead;
            }
            else
            {
                prev->next=newNode;
                prev=newNode;
            }
            curr=curr->next;
        }

         curr=head;
         Node* newCurr=newHead;

         while(curr && newCurr)
         {
            if(!curr->random)
            {
                newCurr->random=NULL;
            }
            else
            {
                newCurr->random=m[curr->random];
            }

            curr=curr->next;
            newCurr=newCurr->next;
         }
         return newHead;
    }
};