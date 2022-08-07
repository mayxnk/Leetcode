class Solution {
public:
//     vector<string> str = {"a","e","i","o","u"};
//     int helper(int n,int i,char c)
//     {
//         if(i == n)
//             return 1;
//         int count = 0;
//         if(c == 'a')
//             count += helper(n,i+1,'e');
//         if(c == 'e')
//         {
//             count += helper(n,i+1,'a');
//             count += helper(n,i+1,'i');
//         }
//         if(c == 'i')
//         {
//             count += helper(n,i+1,'a');
//             count += helper(n,i+1,'e');
//             count += helper(n,i+1,'o');
//             count += helper(n,i+1,'u');
//         }
//         if(c == 'o')
//         {
//             count += helper(n,i+1,'i');
//             count += helper(n,i+1,'u');
//         }
//         if(c == 'u')
//             count += helper(n,i+1,'a');
        
//         return count;
//     }
//     int countVowelPermutation(int n) 
//     {
//         long int mod = 1e7;
//         return (helper(n,1,'a') + helper(n,1,'e') + helper(n,1,'i') + helper(n,1,'o') +                        helper(n,1,'u'))%mod;
//     }
    const int MOD = 1e9 + 7;
    const unordered_map<char, vector<char>> mappings{ {'s', {'a', 'e', 'i', 'o', 'u'} }, // start
                                                      {'a', {'e'}                     }, 
                                                      {'e', {'a', 'i'}                }, 
                                                      {'i', {'a', 'e', 'o', 'u'}      }, 
                                                      {'o', {'i', 'u'}                },
                                                      {'u', {'a'}                     }  };
    unordered_map<char, vector<int>> dp;
public:
    int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
        return solve(n, 's');                         // start with s
    }
    int solve(int rem, char prev) {
        if(rem == 0) return 1;                        // no need to pick further. We have formed 1 string of length = n.
        if(dp[prev][rem]) return dp[prev][rem];       // if result already calculated for current state, directly return it
        for(auto c : mappings.at(prev))               // try each vowel allowed after prev character
            dp[prev][rem] = (dp[prev][rem] + solve(rem - 1, c)) % MOD;  
        return dp[prev][rem];
    }
};