// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool isPrime(int n)
    {
        
        int i,flag = 0;
        for(i = 2;i<=sqrt(n);i++)
        {
            if(n%i == 0)
            {
                flag = 1;
                break;
            }
        }
            
        if(flag == 0)
        return true;
        else
        return false;
    }
	int superPrimes(int n)
	{
	    // Your code goes here
	    //vector<int> prime;
	    unordered_set<int> prime;
	    int i = 2;
	    //Inserting all prime numbers in hashset
	    while(i<=n)
	    {
	        if(isPrime(i))
	        {
	            prime.insert(i);
	        }
	        i++;
	    }
	    int sPrime = 0;
	    unordered_set<int> :: iterator it = prime.begin();
	    for(it;it!=prime.end();it++)
	    {
	        int temp = *it;
	        if(prime.find(temp - 2) != prime.end())
	             sPrime++;
	    }
	    return sPrime;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends