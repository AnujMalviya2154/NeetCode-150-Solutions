class Solution {
public:
    unordered_map<int,vector<int>> preMap;
    unordered_set<int>visitSet;
    unordered_set<int> doneSet;
    vector<int>order;
    bool dfs(int course){
        if(visitSet.count(course)) return false;
        if(doneSet.count(course)) return true;

        visitSet.insert(course);

        for(int pre : preMap[course]){
            if(!dfs(pre)) return false;
        }

        visitSet.erase(course);
        doneSet.insert(course);
        order.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto &pair: prerequisites){
            preMap[pair[0]].push_back(pair[1]);
        }
        for(int course=0; course<numCourses; course++){
            if(!dfs(course)) return{};
        }
        return order;
    }
};
