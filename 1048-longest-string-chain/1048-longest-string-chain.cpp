class Solution {
public:
    static bool compare(string s1,string s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) 
    {
        int len = 1;
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int> dp;
        for(string word : words)
        {
            dp[word] = 1;
            for(int j= 0;j<word.size();j++)
            {
                string preds = word.substr(0,j) + word.substr(j+1);
                if(dp.find(preds) != dp.end())
                {
                    dp[word] = dp[preds] +1;
                    len = max(len,dp[word]);
                }
            }
        }
        return len;
    }
};