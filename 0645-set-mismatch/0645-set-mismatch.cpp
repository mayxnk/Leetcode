class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int i;
         
//         for(i = 0;i<nums.size()-1;++i)
//             if(nums[i] == nums[i+1])
//                 break;

//         ans[0] = nums[i];
//         if((i+2<nums.size() and nums[i]+1==nums[i+2]) or nums[i]==nums.size())
//            ans[1] = nums[i]-1;
//         else
//             ans[1] = nums[i]+1;
//         return ans;
        vector<int> ans(2,-1);
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();++i)
            mp[nums[i]]++;
        for(int i = 1;i<=nums.size();i++)
        {
            if(mp.find(i) == mp.end())
                ans[1] = i;
            if(mp[i] == 2)
                ans[0] = i;
            
            if(ans[0]!=-1 and ans[1]!=-1)
                break;
        }
        return ans;
        
    }
};