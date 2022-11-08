class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<int> st;
        int i = 0;
        while(i<s.size())
        {
            if(st.size() and abs(s[i]-st.top()) == 32)
            {
                st.pop();
                ++i;
                continue;
            }
            st.push(s[i]);
            i++;
        }
        while(st.size()>0)
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};