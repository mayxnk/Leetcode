class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int sum = 0,i = 0,j = 0,n = nums.size(),maxm = INT_MIN;
        unordered_set<int> ch;
        while(i<n && j<n)
        {
            while(ch.find(nums[j]) != ch.end())
            {
                sum -= nums[i];
                ch.erase(nums[i]);
                ++i;
            }
             sum += nums[j];
             ch.insert(nums[j]);
             maxm = max(sum,maxm);
             ++j;
        }
        return maxm;
    }
};