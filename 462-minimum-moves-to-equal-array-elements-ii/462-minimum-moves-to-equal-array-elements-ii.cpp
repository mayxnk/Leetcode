class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        //Median and Sorting Approach,Time - O(nlogn)
        //sort(nums.begin(),nums.end());
        // if(nums[0] == nums[nums.size()-1])
        //     return 0;
        //Using random nth_element function,Time - O(n)
        int n = nums.size();
        nth_element(nums.begin(),nums.begin()+(n/2),nums.end());
        int minm = 0,mid = nums[n/2];
        for(int i = 0;i<n;++i)
            minm += abs(nums[i]-mid);
        return minm;
    }
};