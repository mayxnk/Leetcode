class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[1] < b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int trucksize) 
    {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0,i = boxTypes.size()-1;
        while(trucksize > 0 && i>=0)
        {
            if(boxTypes[i][0] <= trucksize)
            {
                trucksize -= boxTypes[i][0];
                ans += boxTypes[i][0]*boxTypes[i][1];
            }
            else
            {
                if(trucksize > 0)
                {
                    ans += trucksize*boxTypes[i][1];
                    trucksize = 0;
                }
            }
            --i;
        }
        return ans;
    }
};