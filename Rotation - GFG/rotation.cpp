//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    //Brute force
	   /* int minm = INT_MAX,index;
	    for(int i = 0;i<n;i++)
	    {
	        if(arr[i] < minm)
	        {
	            minm = arr[i];
	            index = i;
	        }
	    }
	    return index;
	    */
	    //Optimised Approach
	    int low = 0,high = n-1,minm = INT_MAX,ind;
	    while(low <= high)
	    {
	        int mid = (low+high)/2;
	        if(arr[low] <= arr[high])
	        {
	            if(arr[low] < minm)
	            {
	                minm = arr[low];
	                ind = low;
	            }
	            break;
	        }
	            if(arr[low] <= arr[mid])
	            {
	                if(arr[low] < minm)
	                {
	                    minm = arr[low];
	                    ind = low;
	                }
	                low = mid + 1;
	            }
	            else
	            {
	                if(arr[mid] < minm)
	                {
	                    minm = arr[mid];
	                    ind = mid;
	                }
	                high = mid -1;
	            }
	    }
	    return ind;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends