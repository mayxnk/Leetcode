class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int i = 0,diff = 0;
        priority_queue<int> jumps;
        
        while(i<heights.size()-1)
        {
            diff = heights[i+1] - heights[i];
            if(heights[i+1] <= heights[i])
            {
                ++i;
                continue;
            }
            
            bricks -= diff;
            jumps.push(diff);
            
            if(bricks < 0)
            {
                bricks += jumps.top();
                jumps.pop();
                ladders--;
            }
            if(ladders < 0)
                break;
            i++;
        }
        return i;
    }
};