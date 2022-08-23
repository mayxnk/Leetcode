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
    bool isPalindrome(ListNode* head) 
    {
        // stack<ListNode*> s;
        // ListNode* temp = head;
        // while(temp!=NULL)
        // {
        //     s.push(temp);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(s.size())
        // {
        //     if(s.top()->val != temp->val)
        //         return false;
        //     s.pop();
        //     temp = temp->next;
        // }
        // return true;
        
        // Without using space,Time - O(n)
        ListNode* prev = NULL,*slow = head,*fast = head,*temp;
        while(slow and fast and fast->next)
        {
            fast = fast->next->next;
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        if(fast) //no. of nodes is odd
            slow = slow->next;
        while(slow and prev)
        {
            if(slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};