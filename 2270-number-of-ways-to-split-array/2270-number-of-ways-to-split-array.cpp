class Solution {
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        int count = 0;
        long int sum = 0,sum1 = 0;
        for(int i = 0;i<nums.size();i++)
            sum += nums[i];
        
        for(int i = 0;i<nums.size()-1;i++)
        {
            // int sum1 = 0,t = 0,sum2 = 0; ->this solution giving TLE
            // while(t<=i)
            // {
            //     sum1 += nums[t];
            //     t++;
            // }
            // t = nums.size()-1;
            // while(t>i)
            // {
            //     sum2 += nums[t];
            //     t--;
            // }
            // if(sum1 >= sum2)
            //     count++;
            sum1 += nums[i];
            if(sum1 >= (sum-sum1))
                count++;
        }
        return count;
    }
};