class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        //Time Complexity : O(n*logn),Space : O(n)
        //sorting on basis of last day
        sort(courses.begin(),courses.end(),cmp);
        int time = 0;
        priority_queue<int> maxm;
        
        for(auto &course : courses)
        {
            //If total prev. time + current time is less than equal to current 
            if(time + course[0] <= course[1])
            {
                time += course[0];
                maxm.push(course[0]);
            }
            //Replacing previous longest course with current course
            else if(!maxm.empty() && maxm.top() >= course[0])
            {
                time -= maxm.top();
                time += course[0];
                maxm.pop();
                maxm.push(course[0]);
            }
        }
        return maxm.size();
    }
};