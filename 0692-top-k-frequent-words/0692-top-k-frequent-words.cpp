class Solution {
public:
    static bool cmp(pair<string,int> a,pair<string,int> b)
    {
        // if(!a.compare(0,b.size(),b) or !b.compare(0,a.size(),a))
        //     return a.size() > b.size();
        // else
        //     return a>b;
        if(a.second > b.second or (a.second == b.second and a.first < b.first))
            return true;
        return false;
   
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i = 0;i<words.size();++i)
            mp[words[i]]++;
        vector<pair<string,int>> res;
        for(auto it : mp)
        {
            res.push_back({it.first,it.second});
        }
        sort(res.begin(),res.end(),cmp);
        vector<string> ans;
        int i = 0;
        while(i<k)
        {
            ans.push_back(res[i].first);
            ++i;
        }
        //sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};