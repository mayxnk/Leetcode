class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size()==0 || s.size()==1)
            return s.size();
        
        unordered_set<char> unique;
        int len,maxm = 0;
        for(int i = 0;i<s.size();i++)
        {
            len = 0;
            for(int j = i;j<s.size();j++)
            {
                if(unique.find(s[j]) != unique.end())
                    break;
                unique.insert(s[j]);
                len++;
            }
            maxm = max(maxm,len);
            unique.clear();
        }
        return maxm;
    }
};