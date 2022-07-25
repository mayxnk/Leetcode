class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int i = 0,j = nums.size()-1;
        int n = nums.size();
        vector<int> ans(2,-1);
        //First Occurenece
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(nums[mid] < target)
                i = mid+1;
            else if(nums[mid] > target)
                j = mid-1;
            else
            {
                if(mid == i || nums[mid] != nums[mid-1])
                {
                    ans[0] = mid;
                    break;
                }
                else
                {
                    j = mid - 1;
                    ans[0] = mid - 1;
                }
            }
        }
        //Last Occurence
        i = 0,j = n -1;
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(nums[mid] < target)
                i = mid+1;
            else if(nums[mid] > target)
                j = mid-1;
            else
            {
                if(mid == j || nums[mid] != nums[mid+1])
                {
                    ans[1] = mid;
                    break;
                }
                else
                {
                    i = mid + 1;
                    ans[1] = mid + 1;
                }
            }
        }
        return ans;
       
    }
};