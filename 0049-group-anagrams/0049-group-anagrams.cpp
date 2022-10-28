class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) 
    {
        if(str.size()==1)
            return {{str[0]}};
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        for(auto x:str)
        {
            string temp = x;
            sort(x.begin(),x.end());
            mp[x].push_back(temp);
        }
        for(auto x:mp)
            ans.push_back(x.second);
        return ans;
    }
};