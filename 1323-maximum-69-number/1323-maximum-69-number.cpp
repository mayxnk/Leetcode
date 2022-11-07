class Solution {
public:
    int maximum69Number (int num) {
        int i = 0;
        string s = to_string(num);
        for(i = 0;i<s.size();i++)
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        num = stoi(s);
        return num;
    }
};