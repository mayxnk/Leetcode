/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
public:
    void reverse(ListNode* &head)
    {
        ListNode* prev = NULL,*curr = head,*temp = NULL;
        while(curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        //return prev;
        head = prev;
    }
    void deleteNode(ListNode* node) 
    {
//        ListNode* temp = node,*head;
//         while(temp->next != NULL)
//             temp = temp->next;
        
//         reverse(temp);
//         head = temp;
//         //ListNode* a = node;
//         while(temp != NULL)
//         {
//             if(temp->next != NULL)
//             if(temp->next->val == node->val)
//                 break;
//             temp = temp->next;
//         }
//         if(temp!=NULL)
//         temp->next = node->next;
//         if(node!=NULL)
//         free(node);
//         reverse(head);
        *node = *node->next;
    }
};