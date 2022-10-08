#include<bits/stdc++.h>
class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) 
    {
        sort(num.begin(),num.end());
        int i = 0,j = 0,k = 0,minm = num[0] + num[1] + num[2],n = num.size(),ans;
        if(num[0] == num[n-1])
            return num[0]*3;
        while(i<n-2)
        {
            j = i + 1,k = n-1;
            while(j<k)
            {
                int sum = num[i] + num[j] + num[k];
                if(sum == target)
                {
                    return sum;
                }
               
                    //minm = min(minm,abs(target - sum));
                    if(abs(minm - target)> abs(target - sum))
                    {
                            minm = sum;
                            //ans = sum;
                    }
                   if(sum < target)
                       ++j;
                   else
                       --k;
            }
            while(i<n-2 and num[i] == num[i+1])
                ++i;
            ++i;
        }
        return minm;
    }
};