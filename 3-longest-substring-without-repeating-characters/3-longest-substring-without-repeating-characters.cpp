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
        int count[256] = {0};
        int maxm = 0,left = 0,right = 0;
        while(right<s.size())
        {
            count[s[right]]++;//Adding occurences of character
            while(count[s[right]] > 1)
            {
                count[s[left]]--;
                left++;
            }
            maxm = max(maxm,right-left+1);
            ++right;
        }
        return maxm;
    }
};