class Solution {
public:
    int minDeletions(string s) 
    {
        //Brute Force : Time - O(n^2), Space - O(256) > TLE
        // int f[256] = {0};
        // for(int i = 0;i<s.size();++i)
        //     ++f[s[i]];
        // int minm = 0;
        // for(int i = 0;i<s.size();++i)
        // {
        //     for(int j = 0;j<s.size();++j)
        //     {
        //         if(i!=j and f[s[i]] == f[s[j]] and f[s[i]] > 0 and s[i] != s[j])
        //         {
        //             f[s[i]]--;
        //             ++minm;
        //         }
        //     }
        // }
        // return minm;
        
        //Optimal Approach , Time - O(n), Space - O(1)
        vector<int> f(26,0);
        for(int i = 0;i<s.size();++i)
            f[s[i] - 'a']++;
        sort(f.begin(),f.end());
        int count = 0;
        for(int i = 24;i>=0;--i)
        {
            if(f[i] == 0)
                break;
            if(f[i] >= f[i+1])
            {
                int prev = f[i];
                f[i] = max(0,f[i+1] - 1);
                count += (prev - f[i]);
            }
        }
        return count;
    }
};