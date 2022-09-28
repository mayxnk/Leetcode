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
    int length(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL)
        {
            temp = temp->next;
            ++len;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL)
            return head;
        int l = length(head);
        if(n>l)
            return head;
        if(n == l)
        {
            head = head->next;
            return head;
        }
        int count = l - n,i = 1;
        ListNode* temp = head;
        while(i<count)
        {
            ++i;
            temp = temp->next;
        }  
        if(!temp)
            return head;
        else if(temp->next->next == NULL)
        {
            temp->next = NULL;
            return head;
        }
        else
        {
            ListNode* a = temp->next->next;
            ListNode* b = temp->next;
            temp->next = a;
            return head;
        }
    }
};