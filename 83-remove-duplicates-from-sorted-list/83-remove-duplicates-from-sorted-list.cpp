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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head,*fast = head->next;
        while(slow!=NULL && fast!=NULL)
        {
            if(slow->val == fast->val)
            {
                fast = fast->next;
                delete(slow->next);
                slow->next = fast;
            }
            else
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return head;
    }
};