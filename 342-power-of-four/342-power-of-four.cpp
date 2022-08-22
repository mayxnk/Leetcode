class Solution {
public:
    bool isPowerOfFour(int n) {
    // {
    //     if(n==0)
    //         return false;
    //     if(n==1)
    //         return true;
    //     return (n%4==0 and isPowerOfFour(n/4));
        //Optimised
        //check three conditions:
        /*1.greater than n
        2.only one set bit
        3.Set bit at odd position
        */
        return (n>0) && (n&(n-1))==0 && (n & 0x55555555)!=0;
    }
};