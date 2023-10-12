//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        //Brute force
        /*int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++){
                if(arr[i] + arr[j] == k)
                ++ans;
            }
        }
        return ans;
        */
        //Optimised solution
        int ans = 0;
        unordered_map<int,int> ourMap;
        for(int i = 0;i<n;i++)
        {
            if(ourMap.find(k - arr[i]) != ourMap.end()){
                ans += ourMap[k - arr[i]];
            }
            ourMap[arr[i]]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends