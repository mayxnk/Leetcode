class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int,int> cnt;
        for(int i = 0;i<nums.size();i++)
            cnt[nums[i]]++;
        unordered_map<int,int> endsWith;
        
        for(int i = 0;i<nums.size();++i)
        {
            if(!cnt[nums[i]])
                continue;
            cnt[nums[i]]--;
            if(endsWith[nums[i]-1]>0)
            {
                //if taking nums[i]-1 into consideration,then nums[i] is new tail of this subs.
                endsWith[nums[i]-1]--;
                endsWith[nums[i]]++;
            }
            else if(cnt[nums[i]+1]>0 and cnt[nums[i]+2]>0)
            {
                /*
                if nums[i]+1 and nums[i]+2 are there then we reduce there freq
                and adding a subsequence which is ending with
                nums[i]+2
                */
                cnt[nums[i]+1]--;
                cnt[nums[i]+2]--;
                endsWith[nums[i]+2]++;
            }
            else
                return false;
        }
        return true;
    }
};