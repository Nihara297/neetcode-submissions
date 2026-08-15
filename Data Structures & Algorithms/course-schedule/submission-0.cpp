class Solution {
public:
    bool dfs(int courses, vector<vector<int>>&graph, vector<int>&states){
        if(states[courses]==1){
            return false;
        }
        if(states[courses]==2){
            return true;
        }

        states[courses]=1;
        for(int next:graph[courses]){
            if(!dfs(next, graph, states)){
                return false;
            }
        }
        states[courses]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto p: prerequisites){
            graph[p[0]].push_back(p[1]);
        }
        vector<int>states(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!dfs(i,graph,states)){
                return false;
            }
        }
        return true;
    }
};
