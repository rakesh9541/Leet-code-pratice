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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
            return head;
        int c=1;
        ListNode *cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
            c++;
        }
        k=k%c;
        k=c-k;
        cur->next=head;
        while(k--)
            cur=cur->next;
        head=cur->next;
        cur->next=NULL;
        return head;
        
    }
};