class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(auto x:s)
            mp[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto x:mp)
        {
            pair<int,char> temp;
            temp.first = x.second;
            temp.second = x.first;
            pq.push(temp);
        }
        s = "";
        while(pq.size())
        {
            int ite = pq.top().first;
            char ch = pq.top().second;
            while(ite--)
                s += ch;
            pq.pop();
        }
        return s;
    }
};