// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&a){
        vector <int> v;
        int n,m;
        n=a.size();
        m=n;
        for(int i=0;i<n;i++)
        {
           for(int j=0,k;j<m;j++)
           {
               if(i==0 || i==n-1 || j==0 || j==m-1)
               {
                   v.push_back(a[i][j]);
               }
           }
        }

        
        return v;
        
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int>ans = obj.BoundaryElements(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends