class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> c;
        for(auto ch : sentence)
            c.insert(ch);
        return c.size() == 26;
    }
};