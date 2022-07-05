class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        //Brute Force - O(nlogn),sorting
        int n = nums.size();
        /*if(n<=1)
            return n;
        sort(nums.begin(),nums.end());
        int len = 1,maxm = 1;
        for(int i = 0;i<n-1;++i)
        {
            if(nums[i+1] == nums[i])
                continue;
            if(nums[i+1] == nums[i]+1 )
                ++len;
            else if(nums[i+1] != nums[i]+1 || i == n-2)
            {
                len = 1;
            }
            // else if(nums[i+1] == nums[i])
            //     continue;
            maxm = max(maxm,len);
        }
        return maxm;
        */
        //Optimised Approach - Time : O(n),Space - O(n)
        if(n<=1)
            return n;
        unordered_set<int> s;
        s.insert(nums.begin(),nums.end());
        int maxm = 1,len;
        for(int i = 0;i<n;++i)
        {
            if(s.find(nums[i]-1) != s.end())
                continue;
            else if(s.find(nums[i]-1) == s.end() and s.find(nums[i] + 1) != s.end())
            {
                len = 1;
                int num = nums[i];
                while(s.find(num + 1) != s.end())
                {
                    ++len;
                    ++num;
                }
                maxm = max(len,maxm);
            }
        }
        return maxm;
    }
};