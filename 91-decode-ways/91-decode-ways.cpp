class Solution {
public:
//     int helper(string s,string output[1000000])
//     {
//         int len = s.size();
//         if(len == 0)
//         {
//             output[0] = "";
//             return 1;
//         }
//         if(s[0] == '0')
//             return 0;
//         int num = s[0] - 48;
//         char ch = num + 'a' -1;
//         int ans1 = helper(s.substr(1),output);
        
//         for(int i = 0;i<ans1;i++)
//             output[i] = ch + output[i];
        
//         int ans2 = 0;
//         if(s[1] != '\0')
//         {
//             num = num*10 + s[1] - 48;
//             ch = num - 1 + 'a';
//             if(num > 9 and num <= 26)
//             {
//                   ans2 = helper(s.substr(2),output + ans1);
//                   for(int k = 0;k<ans2;++k)
//                   output[k+ans1] = ch + output[k+ans1];
//               }
//         }
//         return ans1 + ans2;
        
//     }
//     int numDecodings(string s) {
//         string output[1000000];
//         if(s[0] == '0')
//             return 0;
//         return helper(s,output);
//     }
       int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n+1,-1);
        mem[n]=1;
        return s.empty()? 0 : num(0,s,mem);   
    }
    int num(int i, string &s, vector<int> &mem) {
        if(mem[i]>-1) return mem[i];
        if(s[i]=='0') return mem[i] = 0;
        int res = num(i+1,s,mem);
        if(i<s.size()-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) res+=num(i+2,s,mem);
        return mem[i] = res;
    }
};