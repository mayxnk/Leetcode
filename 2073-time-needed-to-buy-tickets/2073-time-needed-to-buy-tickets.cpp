class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int val = tickets[k];
        tickets[k] = -1;
        queue<int> line;
        for(auto i :tickets)
            line.push(i);
        int t = 0;
        while(!line.empty())
        {
            if(line.front() == 0)
            {
                line.pop();
            }
            else
            {
                if(line.front() == -1)
                {
                    --val;
                    ++t;
                    line.pop();
                    line.push(-1);
                    if(val == 0)
                        return t;
                    continue;
                }
                int temp = line.front();
                line.pop();
                --temp;
                ++t;
                line.push(temp);
            }
        }
        return t;
    }
};