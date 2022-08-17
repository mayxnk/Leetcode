class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> a{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> ans;
        for(int i = 0;i<words.size();i++)
        {
            string temp = "";
            for(int j = 0;j<words[i].size();j++)
            {
                temp += (a[words[i][j] - 'a']);
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};