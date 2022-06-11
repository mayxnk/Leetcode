class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> ans(spells.size());
        
        // for(int i = 0;i<spells.size();++i)
        // {
        //     int count = 0;
        //     for(int j = 0;j<potions.size();++j)
        //     {
        //         if((long)spells[i]*potions[j] >= success)
        //             ++count;
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
        //Time - O(nlogn)
        sort(potions.begin(),potions.end());
        
        int low,high,mid,count,m = potions.size();
        
        for(int i = 0;i<spells.size();i++)
        {
            low = 0,high = m-1,count = m;
            while(low<=high) //Binary search for potion
            {
                mid = low + (high - low)/2;
                if((long long)spells[i] * potions[mid] >= success) //All greater value of potions will be counted
                {
                    count = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            ans[i] = m - count;
        }
        return ans;
    }
};