//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
    //Code here
    //Brute force
    /*int maxm = 0;
      for(int i = 0;i<n;i++){
          for(int j = i+1;j<n;j++){
              if(arr[i] == arr[j])
              maxm = max(maxm,j-i);
          }
      }
      return maxm;
      */
      unordered_map<int,int> store;
      int maxm = 0;
      for(int i = 0;i<n;i++){
          if(store.find(arr[i]) != store.end()){
              maxm = max(maxm,i - store[arr[i]]);
          }
          else{
              store[arr[i]] = i;
          }
      }
      return maxm;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends