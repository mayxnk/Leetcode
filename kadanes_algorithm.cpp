//largest sum contiguous subarray of time complexity O (n)
#include <iostream>
using namespace std;
int maxSumSubarray(int a[], int n)
{
   int i, currsum = 0, maxsum = 0;
   for (i = 0; i < n; i++)
   {
      currsum += a[i];
      // if(currsum>maxsum)
      // maxsum=currsum;  OR,
      maxsum = max(maxsum, currsum);
      if (currsum < 0)
         currsum = 0;
   }
   return maxsum;
}
int main()
{
   int a[] = {2, 1, -3, 2, 7};
   int a_size = sizeof(a) / sizeof(a[0]);

   int max_sum = maxSumSubarray(a, a_size);
   cout << "Largest sum in contiguous subarray: " << max_sum << endl;
   return 0;
}