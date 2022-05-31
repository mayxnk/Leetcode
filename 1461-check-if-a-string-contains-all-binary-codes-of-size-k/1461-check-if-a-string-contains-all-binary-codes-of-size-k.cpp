class Solution {
public:
   void helper(vector<string>& bCode,int k,int i,int *a)
    {
        //base case
        if(i == k)
        {
        	string str = "",temp = "";
			// for(int i = 0;i<k;i++)
			// {
			// 	temp.append(to_string(a[i]));
			// }
            transform(a,a+k,back_inserter(str),[](int const &i) {
                        return i + '0';
                    });
            bCode.push_back(str);
            return;
        }
        a[i] = 0;
        helper(bCode,k,i+1,a);
        a[i] = 1;
        helper(bCode,k,i+1,a);
    }
    bool hasAllCodes(string s, int k) 
    {
        //Brute force
        // if((s.size()==0 && k!=0) || k>s.size())
        //     return false;
        // if(s.size() == 1)
        // {
        //     if(k >= 1)
        //         return false;
        //     else
        //         return true;
        // }
        // vector<string> bCode;
        // int str[k];
        // helper(bCode,k,0,str);
        // int count = 0;
        // // for(int i = 0;i<bCode.size();i++)
        // // cout<<bCode[i]<<endl;
        // for(int i = 0;i<=s.size()-k;i++)
        // {
        //     string temp = s.substr(i,k);
        //     for(int j = 0;j<bCode.size();j++)
        //     {
        //         if(temp == bCode[j])
        //             count++;
        //     }
        // }
        // if(count<bCode.size())
        //     return false;
        // return true;
        
        if(k > s.size()) return false;
        unordered_set<string> bCode;
        
        for(int i = 0;i<=s.size()-k;i++)
            bCode.insert(s.substr(i,k));
        
        return bCode.size() == pow(2,k);
}
};