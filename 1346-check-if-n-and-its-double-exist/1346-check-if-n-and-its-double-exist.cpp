class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        /** Time - O(n), Space - O(n) **/
        // unordered_map<int,int> mp;
        // for(int i = 0;i<arr.size();++i)
        //     mp[arr[i]] = i;
        // for(int i = 0;i<arr.size();++i)
        // {
        //     if(mp.find(arr[i]*2) != mp.end() and i != mp[arr[i]*2])
        //         return true;
        // }
        // return false;
        
        /** **/
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size();++i)
        {
            int key = arr[i] * 2,s = 0,e = arr.size()-1;
            while(s <= e)
            {
                int mid = (s+e)/2;
                if(arr[mid] == key and mid != i)
                    return true;
                else if(arr[mid] < key)
                    s = mid + 1;
                else
                    e = mid -1;
            }
        }
        return false;
    }
};