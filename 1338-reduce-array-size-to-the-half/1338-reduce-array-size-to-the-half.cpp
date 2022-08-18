class Solution {
public:
    int minSetSize(vector<int>& arr) 
{
//         int n = arr.size();
//         unordered_map<int,int> freq;
//         unordered_set<int> s;
//         for(int i = 0;i<n;i++)
//         {
//             freq[arr[i]]++;
//             s.insert(arr[i]);
//         }

//         int count = 0,c = 0,ans = INT_MAX;
//         for(auto i : s)
//         {
//             count = 1;
//             c = freq[i];
//             for(auto j: s)
//             {
//                 if(c >= n/2)
//                 {
//                     c = freq[i];
//                     count = 1;
//                     ans = min(ans,count);
                    
//                 }
//                 if(i!=j)
//                 {
//                     c += freq[j]; 
//                     count++;
//                 }
                    
//             }
//         }
//         return ans;
        unordered_map<int, int>mp;
        priority_queue<int> pq;
		for(auto num : arr) mp[num]++;                  
        for(auto [num, freq] : mp) pq.push(freq);
        for(int deleted{}, ans{}; ;pq.pop()) {
            deleted += pq.top(), ans++;
            if(deleted >= size(arr) / 2) return ans;    
        }
        return -1;
    }
};