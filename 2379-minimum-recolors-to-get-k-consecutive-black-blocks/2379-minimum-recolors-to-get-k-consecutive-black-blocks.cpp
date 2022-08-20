class Solution {
public:

    int minimumRecolors(string blocks, int k) 
    {
        int n = blocks.size();
        // if(k>n)
        //     return 0;
        // int cnt = 1,flag = false;
        // for(int i = 0;i<n-k;++i)
        // {
        //     int cnt = 1,count = 0;
        //     if(blocks[i] == 'W')
        //         cnt = 0;
        //     for(int j = i+1;j<n;++j)
        //     {
        //         if(blocks[j] == 'B')
        //             ++cnt;
        //         else
        //             cnt = 0;
        //         if(cnt == k)
        //         {
        //             flag = true;
        //             break;
        //         }
        //     }
        // }
        // if(flag)
        //     return 0;
        int i = 0,j = 0,wCount = 0,bCount = 0,ans = INT_MAX;
        while(j<n)
        {
            if(j<n and blocks[j] == 'W')
                wCount++;
            else
                bCount++;
            if(j-i+1 == k)
            {
                ans = min(ans,wCount);
                if(blocks[i] == 'W')
                    wCount--;
                else
                    bCount--;
                i++;
            }
            ++j;
        }
        return ans;
       
    }
};