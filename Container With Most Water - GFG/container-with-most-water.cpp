//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int len)
{
    // Your code goes here
    //Optimised code
    long long maxm = 0,i = 0,j = len-1;
    while(i<j)
    {
        maxm = max(maxm,min(a[i],a[j])*(j-i));
        if(a[j]>a[i])
        ++i;
        else
        --j;
    }
    return maxm;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends