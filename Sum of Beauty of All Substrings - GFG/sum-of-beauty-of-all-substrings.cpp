//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int find(vector<int>& v)
    {
        int mx = INT_MIN,mn = INT_MAX;
        for(int x:v)
        {
            if(x == 0)
            continue;
            mx = max(mx,x);
            mn = min(mn,x);
        }
        return mx-mn;
    }
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        for(int i = 0;i<s.size();i++)
        {
            vector<int> v(26,0);
            for(int j = i;j<s.size();j++)
            {
                v[s[j]-'a']++;
                ans += find(v);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends