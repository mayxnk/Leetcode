class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        /*int ans = 0;
        sort(amount.begin(),amount.end());
        while((amount[1]>0 and amount[2]>0))
        {
            if(amount[1]>0 and amount[2]>0)
            {
                amount[1]--;
                amount[2]--;
                ++ans;
            }
            sort(amount.begin(),amount.end());
        }
        while((amount[1]>0 and amount[2]>0))
        {
            if(amount[1]>0 and amount[2]>0)
            {
                amount[1]--;
                amount[2]--;
                ++ans;
            }
            sort(amount.begin(),amount.end());
        }
        sort(amount.begin(),amount.end());
        while(amount[2] > 0)
        {
            ++ans;
            --amount[2];
        }
        return ans;
        */
        priority_queue<int> pq;
        for(auto i:amount)
            pq.push(i);
        int ans = 0;
        while(pq.top()!=0)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a > 0 and b > 0)
            {
                pq.push(--a);
                pq.push(--b);
                ++ans;
            }
            else
            {
                pq.push(--a);
                pq.push(b);
                ++ans;
            }
        }
        return ans;
    }
};