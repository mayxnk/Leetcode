class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> mp;
        unordered_map<char,int> sp;
        for(int i = 0;i<t.size();i++)
            mp[t[i]]++;
        for(int i = 0;i<s.size();i++)
            sp[s[i]]++;
        if(sp.size()!=mp.size())
            return false;
        for(int i = 0;i<t.size();i++)
        {
            if(mp[t[i]] != sp[t[i]])
                return false;
        }
        return true;
    }
};