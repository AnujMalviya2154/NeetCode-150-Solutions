class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for(int task:tasks){
            freq[task-'A']++;
        }

        int maxFreq = 0;

        for(int f: freq){
            maxFreq = max(f,maxFreq);
        }

        int countMax = 0;

        for(int f: freq){
            if(f == maxFreq) countMax++;
        }

        int forced = (maxFreq-1)*(n+1)+countMax;

        return max((int)tasks.size(),forced);
    }
};
