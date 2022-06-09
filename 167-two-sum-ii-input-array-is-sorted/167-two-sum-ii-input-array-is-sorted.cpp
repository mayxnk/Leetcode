class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans(2);
        //Brute Force
        // for(int i = 0;i<nums.size()-1;i++)
        // {
        //     for(int j = i+1;j<nums.size();j++)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {
        //             ans[0] = i+1;
        //             ans[1] = j+1;
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        //Brute Force 
//         unordered_map<int,int> map;
//         for(int i = 0;i<nums.size();i++)
//             map[nums[i]] = i;
        
//         for(int i = 0;i<nums.size();i++)
//         {
//             if(map.find(target - nums[i]) != map.end() && map[target - nums[i]] > i)
//             {
//                 ans[0] = i+1;
//                 ans[1] = map[target - nums[i]] + 1;
//                 break;
//             }
//         }
//         return ans;
        
        //Optimal Approach - Two Pointers
        int low = 0,high = nums.size() - 1;
        while(low < high)
        {
            if(nums[low] + nums[high] == target)
            {
                ans = {low + 1,high + 1};
                break;
            }
            else if(nums[low] + nums[high] < target)
                ++low;
            else
                --high;
        }
        return ans;
    }
};