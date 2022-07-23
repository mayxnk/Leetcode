class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans = 0,count = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(nums[i] == 0)        //Increasing count of zeroes
                ++count;
            else                    //If we encounter a non-zero element,then count number of subarrays by no.
                                    //of zeroes,then make count of zeroes to zero again
            {
                ans += (count*(count+1))/2; //Formula - Number of subarrays = n*(n+1)/2
                count = 0;
            }
        }
        if(count > 0)
            ans += (count*(count+1))/2;
        
        return ans;
        
    }
};