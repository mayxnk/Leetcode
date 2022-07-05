class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1)
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
    }
};