class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        int i = 0,j = 0,ans = 0;
        unordered_map<char,int> mp;
        while(j < s.size())
        {
            mp[s[j]]++;
            if(j-i+1 < 3)
                ++j;
            else if(j-i+1 == 3)
            {
                // int count = 0;
                // for(auto x:mp)
                // {
                //     if(x.second == 1)
                //     {
                //         count++;
                //     }
                // }
                // if(count == 3)
                //     ++ans;
                if(mp.size()==3)
                    ++ans;
                //Slide Window
                if(mp[s[i]] > 1)
                    mp[s[i]]--;
                else
                    mp.erase(s[i]);
                ++i;
                ++j;
            }
        }
        return ans;
    }
};