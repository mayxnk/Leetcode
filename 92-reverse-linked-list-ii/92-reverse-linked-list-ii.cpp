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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head == NULL)
            return NULL;
        /*ListNode* prev1 = NULL,*prev2 = NULL,*curr1 = head,*curr2 = head,*a = NULL;
        int i = 1;
        while(i<left)
        {
            prev1 = curr1;
            curr1 = curr1->next;
            ++i;
        }
        i = 1;
        while(i<right)
        {
            prev2 = curr2;
            curr2 = curr2->next;
            ++i;
        }
        if(curr2)
        a = curr2->next;
        ListNode* c = curr1,*prev = NULL,*n = NULL;
        while(c != curr2)
        {
            n = c->next;
            c->next = prev;
            prev = c;
            c = n;
        }
        if(prev1)
        prev1->next = prev;
        if(curr1)
        curr1->next = a;
        return head;
        */
        if(head==NULL || head->next==NULL){return head;} // Base case:- If there are no nodes or only a single node. 
        
        ListNode* dummy=new ListNode(-1); // Creating a dummy node.
        dummy->next=head; // Making connection of the dummy node to head.
        
        // Creating pointers for traversal which will further help in making connections after the reversal operation.
        ListNode* previt=NULL; 
        ListNode* it=dummy;
        
        // Traverse till the left node which is the beginning node for the reversal part of the linked list. 
        for(int i=0;i<left;i++){
            previt=it;
            it=it->next;
        }
        
        // Appointing pointers to the left node and its previous node to help in reversal operation.
        ListNode* curr=it;
        ListNode* prev=previt;
        
        
        // Traverse till the right node which is the ending point for the reverse operation and reverse nodes side by side as done in "Reverse Linked List 1(Leetcode no. 206)"
        for(int i=left;i<=right;i++){
            ListNode* Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        
        // Make connections 
        previt->next=prev;
        it->next=curr;
        
        return dummy->next;
        
    }
};