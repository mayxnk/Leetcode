class Solution {
public:
    void rev(string& s,int i,int j)
    {
        while(i<=j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    string reverseWords(string s) 
    {
        int i = 0,j = 0;
        while(j<s.size())
        {
            if(s[j] == ' ')
            {
                rev(s,i,j-1);
                i = j+1;
            }
            else if(j == s.size()-1)
            {
                rev(s,i,j);
            }
            ++j;
        }
        return s;
    }
};