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
        //insertion
        Node* curr=head;
        while(curr)
        {
            Node* newNode=new Node(curr->val);
            Node* temp=curr->next;
            curr->next=newNode;
            newNode->next=temp;
            curr=temp;
        }

        //random pointer management
        curr=head;

        while(curr)
        {
                if(curr->random)
                    curr->next->random = curr->random->next;
                else
                    curr->next->random = NULL;

                curr = curr->next->next;
        }

        //speration of both ll
        curr=head;
        Node* newHead=curr->next;
        Node* newCurr=curr->next;

        while(curr && newCurr)
        {
            curr->next=(curr->next==NULL) ? NULL : curr->next->next;
            newCurr->next=(newCurr->next==NULL) ? NULL : newCurr->next->next;
            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;
    }
};