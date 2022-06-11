class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int sum1 = 0,sum2 = 0,len = 0;
        for(int i = 0;i<nums.size();i++)
            sum2 += nums[i];
        
        sum2 -= x;
        if(!sum2)
            return nums.size();
        
        int j = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum1 += nums[i];
            
            while(j<nums.size() && sum1 > sum2)
                sum1 -= nums[j++];
            
            if(sum1 == sum2)
                len = max(len,i-j+1);
        }
        if(len>0)
            return nums.size()-len;
        return -1;
    }
};