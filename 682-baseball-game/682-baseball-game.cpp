#include<bits/stdc++.h>
class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int> sc;
        int total = 0,temp,a,b;
        for(int i = 0;i<ops.size();i++)
        {
            if(ops[i] == "C")
                sc.pop();
            else if(ops[i] == "+")
            {
                if(!sc.empty())
                a = sc.top();
                sc.pop();
                if(!sc.empty())
                b = sc.top();
                temp = a+b;
                sc.push(a);
                sc.push(temp);
            }
            else if(ops[i] == "D")
            {
                if(!sc.empty())
                temp = sc.top();
                sc.push(2*temp);
            }
            else
            {
                int num = stoi(ops[i]);
                sc.push(num);
            }
        }
        while(!sc.empty())
        {
            if(!sc.empty())
            total += sc.top();
            sc.pop();
        }
         return total;   
    }
};