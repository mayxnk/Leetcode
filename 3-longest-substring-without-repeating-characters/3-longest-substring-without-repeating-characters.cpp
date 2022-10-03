class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size()==0 || s.size()==1)
            return s.size();
        //Brute Force Approach
        /*
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
        */
        //Optimal Approach - Time:O(2*n),Space:O(m)
        /**Sliding window technique**/
        // int count[256] = {0};
        // int maxm = 0,left = 0,right = 0;
        // while(right<s.size())
        // {
        //     count[s[right]]++;//Adding occurences of character
        //     while(count[s[right]] > 1)
        //     {
        //         count[s[left]]--;
        //         left++;
        //     }
        //     maxm = max(maxm,right-left+1);
        //     ++right;
        // }
        // return maxm;
        unordered_map<int,int> mp;
        int i = 0,j = 0,maxm = 0;
        while(j<s.size())
        {
            mp[s[j]]++;
            if(mp.size() == j-i+1)
                maxm = max(maxm,j-i+1);
            else
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    ++i;
                }
            }
            ++j;
        }
        return maxm;
    }
};