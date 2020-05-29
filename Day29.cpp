//Course Schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> req(numCourses,0);
        for(int i = 0; i<n; i++) req[prerequisites[i][0]]++;
        
        stack <int> s;
        for(int i=0; i<numCourses; i++){
            if(req[i] == 0) s.push(i);
        }
        while(!s.empty()){
            int cur = s.top();
            s.pop();
            for(int i = 0; i<n; i++){
                if(prerequisites[i][1] == cur){
                    req[prerequisites[i][0]] --;
                    if(req[prerequisites[i][0]] == 0) s.push(prerequisites[i][0]);
                }
            }
        }
        for(int i =0; i<numCourses; i++)
            if(req[i]>0) return false;
        return true;
    }
};