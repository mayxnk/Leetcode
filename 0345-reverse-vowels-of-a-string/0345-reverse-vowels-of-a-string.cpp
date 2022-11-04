class Solution {
public:
    string reverseVowels(string str) 
    {
        int i = 0,j = str.size()-1;
        unordered_set<char> s;
        s.insert('a'),s.insert('e'),s.insert('i'),s.insert('o'),s.insert('u');
        s.insert('A'),s.insert('E'),s.insert('I'),s.insert('O'),s.insert('U');
        while(i<j)
        {
            if(s.find(str[i])!=s.end() and s.find(str[j])!=s.end())
            {
                swap(str[i],str[j]);
                ++i;
                --j;
            }
            else if(s.find(str[i])==s.end())
                i++;
            else
                j--;
        }
        return str;
    }
};