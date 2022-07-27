class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> ch;
        for(auto x : emails)
        {
            string temp = "";
            int j = 0;
            for(j = 0;x[j]!='@';j++)
            {
                if(x[j] == '+')
                    break;
                else if(x[j] == '.')
                    continue;
                temp += x[j];
            }
            while(x[j]!='@')
                ++j;
            while(j<x.size())
            {
                temp += x[j];
                ++j;
            }
            ch.insert(temp);
        }
        return ch.size();
    }
};