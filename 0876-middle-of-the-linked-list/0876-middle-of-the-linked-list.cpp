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
    ListNode* middleNode(ListNode* head) {
        int n=len(head);
        int pos=n/2;
        while(pos>0)
        {
            head=head->next;
            pos--;
        }
        return head;
    }
};