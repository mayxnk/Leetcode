class Solution {
public:
    bool reorderedPowerOf2(int N) {
        //Counting of digits approach
        map<int,vector<int>> fq;
        int x = pow(10,9);
        for(int i = 1;i<=x;i*=2) //log(10^9)
        {
            vector<int> temp(10,0);
            int k = i;
            while(k>0) //max nine times
            {
                temp[k%10]++;
                k/=10;
            }
            fq[i] = temp;
        }
        vector<int> num(10,0);
        for(int i = N;i>0;i/=10)
        {
            num[i%10]++;
        }
        for(int i = 1;i<=x;i*=2)
        {
            vector<int> temp = fq[i];
            bool flag = true;
            // for(int j = 0;j<=9;++j)
                if(temp == num)
                    return true;;
            // if(flag)
            //     return true;
        }
        return false;
        
        
    }
};