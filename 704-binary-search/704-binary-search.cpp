class Solution {
public:
    int helper(vector<int>& nums,int low,int high,int target)
    {
        if(low>high)
            return -1;
        else
        {
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                return helper(nums,mid+1,high,target);
            else
                return helper(nums,low,high-1,target);
            
        }
    }
    int search(vector<int>& nums, int target) 
    {
        return helper(nums,0,nums.size()-1,target);
    }
};