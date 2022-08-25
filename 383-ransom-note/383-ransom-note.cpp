class Solution {
public:
    bool canConstruct(string r, string m) 
    {
        //unordered_map<char,int> mp1,mp2;
        // for(auto x:r)
        //     mp1[x]++;
        int mp2[26] = {0};
        for(auto x:m)
            mp2[x-'a']++;
        
//         for(int i = 0;i<r.size();i++)
//         {
//             if(mp2.find(r[i]) == mp2.end() or mp1[r[i]] > mp2[r[i]])
//                 return false;
//         }
//         return true;
        
        for(int i = 0;i<r.size();i++)
        {
            if(mp2[r[i]-'a'] == 0)
                return false;
            else
                mp2[r[i]-'a']--;
        }
        return true;
        
           
    }
};