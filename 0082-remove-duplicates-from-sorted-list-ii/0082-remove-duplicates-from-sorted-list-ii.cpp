/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* dummyhead= new ListNode(0,head);
        ListNode* prev =dummyhead;
            if(head == NULL){
                return head; 
            }
        while(curr != NULL && curr->next !=NULL){
            if(curr->val == curr->next->val ){
                while(curr->next !=NULL && curr->val == curr->next->val){
                    curr=curr->next;
                }prev->next=curr->next;
                if(curr->next != NULL)
                    curr=curr->next;
            }else{
                prev=curr;
                curr=curr->next;
            }

        }return dummyhead->next;
}
};