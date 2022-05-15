// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool compare(int count1[],int count2[])
    {
        for(int i=0;i<256;i++)
        {
            if(count1[i]==count2[i])
            continue;
            else
            return false;
        }
        return true;
    }
	int search(string pat, string txt) {
	    int N=txt.length();
	    int M=pat.length();
	    int count1[256];
	    int count2[256],cnt=0;
	    
	    for(int i=0;i<256;i++)
	    {
	        count1[i]=0;
	        count2[i]=0;
	    }
	    for(int i=0;i<M;i++)
	    {
	        count1[txt[i]]++;
	        count2[pat[i]]++;
	    }
	    if(compare(count1,count2))
	    cnt++;
	    for(int i=1;i<=N-M;i++)
	    {
	        count1[txt[M+i-1]]++;
	        count1[txt[i-1]]--;
	        if(compare(count1,count2))
	        cnt++;
	    }
	    return cnt;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends