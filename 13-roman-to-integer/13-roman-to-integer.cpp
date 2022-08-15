class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> mp;
        mp['I'] = 1,mp['V'] = 5,mp['X'] = 10,mp['L'] = 50;
        mp['C'] = 100,mp['D'] = 500,mp['M'] = 1000;
//         mp["IV"] = 4,mp["IX"] = 9,mp["XL"] = 40,mp["XC"] = 90;
//         mp["CP"] = 400,mp["CM"] = 900;
        
         int sum = 0,i = 0,size = s.size();
        // while(i<size)
        // {
        //     if(s[i] == 'I')
        //     {
        //         if(i<size-1 and s[i+1] == 'V')
        //         {
        //             sum += 4;
        //             i+=2;
        //             continue;
        //         }
        //         else if(i<size-1 and s[i+1] == 'X')
        //         {
        //             sum += 9;
        //             i+=2;
        //             continue;
        //         }
        //         else
        //             ++sum;
        //     }
        //     else if(s[i] == 'X')
        //     {
        //         if(i<size-1 and s[i+1] == 'L')
        //         {
        //             sum += 40;
        //             i+=2;
        //             continue;
        //         }
        //         else if(i<size-1 and s[i+1] == 'C')
        //         {
        //             sum += 90;
        //             i+=2;
        //             continue;
        //         }
        //         else
        //             sum += 10;
        //     }
        //     else if(s[i] == 'C')
        //     {
        //         if(i<size-1 and s[i+1] == 'D')
        //         {
        //             sum += 400;
        //             i+=2;
        //             continue;
        //         }
        //         else if(i<size-1 and s[i+1] == 'M')
        //         {
        //             sum += 900;
        //             i+=2;
        //             continue;
        //         }
        //         else
        //             sum += 100;
        //     }
        //     else
        //         sum += mp[s[i]];
        //     ++i;
        // }
        // return  sum;
        /*Approach 2*/
        while(i<size)
        {
            if(i<size-1 and mp[s[i]]<mp[s[i+1]])
                sum -= mp[s[i]];
            else
                sum += mp[s[i]];
            ++i;
        }
        return sum;
    }
};