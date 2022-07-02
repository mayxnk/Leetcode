class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) 
    {
        int mod = 1e9 + 7;
        vC.push_back(w);
        hC.push_back(h);
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        int ans1 = hC[0],ans2 = vC[0];
        for(int i = 1;i<hC.size();++i)
            ans1 = max(ans1,hC[i]-hC[i-1]);
        for(int i = 1;i<vC.size();++i)
            ans2 = max(ans2,vC[i]-vC[i-1]);
        
        return (1LL*ans1*ans2)%mod;
    }
};