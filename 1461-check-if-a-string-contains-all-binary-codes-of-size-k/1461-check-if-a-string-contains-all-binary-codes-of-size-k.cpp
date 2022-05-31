class Solution {
public:
    void helper(vector<string>& bCode,int k,int i,string str)
    {
        //base case
        if(i == k)
        {
            bCode.push_back(str);
            return;
        }
        str[i] = 0;
        helper(bCode,k,i+1,str);
        str[i] = 1;
        helper(bCode,k,i+1,str);
    }
    bool hasAllCodes(string s, int k) 
    {
//         if(s.size()==0 && k!=0)
//             return false;
//         vector<string> bCode;
//         string str;
//         helper(bCode,k,0,str);
        
//         for(int i = 0;i<bCode.size();i++)
//         {
//             string temp = bCode[i];
//             int j,count = 0;
//             for(j = 0;j<=s.size()-k;j++)
//             {
//                 string s1 = s.substr(j,k);
//                 if(temp == s1)
//                 {
//                     count++;
//                     break;
//                 }
//             }
//             if(count == 0)
//                 return false;
//         }
//         return true;
        if(k > s.size()) return false;
    
    unordered_set<string> res_set;
    
	//Insertion into the set
    for(int i =0;i<= s.size()-k;i++)
        res_set.insert(s.substr(i,k));
    
	//Comparing res with 2^k
    return res_set.size() == pow(2,k);
    }
};