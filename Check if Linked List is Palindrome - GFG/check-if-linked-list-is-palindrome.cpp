// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    void helper(Node* head,vector<int>& v)
    {
        if(head==NULL)
        return;
        
        helper(head->next,v);
        v.push_back(head->data);
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> v;
        helper(head,v);
        
        Node* temp = head;
        int s = 0;
        while(temp!=NULL)
        {
            if(temp->data != v[s])
            return false;
            temp = temp->next;
            ++s;
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends