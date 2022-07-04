class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int> candy(n,1);
        
        for(int i = n-2;i>=0;--i)//for strictly decreasing vales
            if(ratings[i] > ratings[i+1])
                candy[i] = 1 + candy[i+1];
        int ans  = 0;
        //calculating candies for strictly increasing and final ans 
        for(int i = 0;i<n-1;++i)
        {
            if(ratings[i] < ratings[i+1])
                candy[i+1] = max(candy[i+1],1 + candy[i]);
            ans += candy[i];
        }
        return ans + candy[n-1];//final ans + candy of n-1th child
    }
};