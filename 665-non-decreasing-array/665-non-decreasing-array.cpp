class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int count = 0;
        for(int i = 1;i<nums.size();++i)
        {
           if(nums[i] < nums[i-1])
           {
               ++count;
               if(count > 1 || (i > 1 and i < nums.size()-1) and nums[i-2] > nums[i] and                              nums[i-1] > nums[i+1] )
                   return false;
           }
        }
        return true;
    }
};