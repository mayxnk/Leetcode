//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        stack<int> sp;
        int cnt = 0,rs = 0,re = R-1,cs = 0,ce = C-1,i;
        while(cnt<R*C)
        {
            for(i = cs;i<=ce;i++)
            {
                sp.push(a[rs][i]);
                ++cnt;
            }
            ++rs;
            for(i = rs;i<=re;i++)
            {
                sp.push(a[i][ce]);
                ++cnt;
            }
            --ce;
            if(rs<=re)
            for(i = ce;i>=cs;i--)
            {
                sp.push(a[re][i]);
                ++cnt;
            }
            --re;
            if(cs<=ce)
            {
                for(i = re;i>=rs;i--)
                {
                    sp.push(a[i][cs]);
                    ++cnt;
                }
            }
            ++cs;
        }
        vector<int> ans(R*C);
        i = 0;
        while(sp.size()!=0)
        {
            ans[i++] = sp.top();
            sp.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends