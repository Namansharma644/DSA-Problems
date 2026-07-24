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
    ListNode* merge2List(ListNode* l1,ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* res=NULL;
        if(l1->val<l2->val)
        {
            res=l1;
            res->next=merge2List(l1->next,l2);
        }
        else
        {
            res=l2;
            res->next=merge2List(l1,l2->next);
        }
        return res;
    }
    ListNode*  partitonAndMerge(int si,int ei,vector<ListNode*>& lists)
    {
        if(si==ei)
        {
            return lists[si];
        }

        if(si>ei)
        {
            return NULL;
        }
        int mid=si+(ei-si)/2;
        ListNode* l1=partitonAndMerge(si,mid,lists);
        ListNode* l2=partitonAndMerge(mid+1,ei,lists);

        return merge2List(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        return partitonAndMerge(0,k-1,lists);
    }
};