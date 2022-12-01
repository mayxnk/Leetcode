class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0,count2 = 0;
        for(int i = 0;i<s.size()/2;i++)
        {
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or
              s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
                ++count1;
        }
        for(int i = s.size()/2;i<s.size();i++)
        {
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or
              s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U')
                ++count2;
        }
        return count1 == count2;
    }
};