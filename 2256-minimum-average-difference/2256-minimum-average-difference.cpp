class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pf(n);
        pf[0] = nums[0];
        for(int i = 1;i<n;i++)
            pf[i] = pf[i-1] + nums[i];
        
        int ans = 0,minm = INT_MAX;
        for(int i = 0;i<n;i++)
        {
            //long long k = abs((pf[i]/(i+1)) - ((pf[n-1] - pf[i])/(max(n-i-1,1))));
            long long t1,t2,k;
            t1 = pf[i]/(i+1);
            int div = max(n-i-1,1);
            t2 = (pf[n-1]-pf[i])/div;
            k = abs(t1-t2);
            if(k<minm)
            {
                minm = k;
                ans = i;
            }
        }
        return ans;
    }
};