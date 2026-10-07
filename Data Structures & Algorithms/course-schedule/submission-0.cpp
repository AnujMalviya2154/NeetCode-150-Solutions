class Solution {
public:
    unordered_map<int,vector<int>>preMap;
    unordered_set<int>visitSet;
    bool dfs(int course){
        if(visitSet.count(course)) return false;
        if(preMap[course].empty()) return true;

        visitSet.insert(course);

        for(int pre : preMap[course]){
            if(!dfs(pre)) return false;
        }
        visitSet.erase(course);
        preMap[course].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto &pair : prerequisites){
            preMap[pair[0]].push_back(pair[1]);
        }
        for(int course=0; course<numCourses; course++){
            if(!dfs(course)){
                return false;
            }
        }
        return true;
    }
};
