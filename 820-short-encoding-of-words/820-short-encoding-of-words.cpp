class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        //Adding all words in a set
        set<string> s(words.begin(),words.end());
        
        for(auto& word : words)
        {
            for(int i = 1;i<word.size();++i)
                s.erase(word.substr(i));//Deleting all suffixes from set
        }
        //Now words with valid encoding are present
        int ans = 0;
        for(auto word : s)
        {
            ans += word.size() + 1; // +1 for #
        }
        return ans;
    }
};