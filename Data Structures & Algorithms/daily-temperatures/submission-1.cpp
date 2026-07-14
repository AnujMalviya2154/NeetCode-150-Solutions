class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> answer(n, 0);

        stack<int> st;          // stores indices

        for(int i = n - 1; i >= 0; i--) {

            // Remove all temperatures that are
            // not warmer than today's temperature.
            while(!st.empty() &&
                  temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack isn't empty,
            // top is the next warmer day.
            if(!st.empty()) {
                answer[i] = st.top() - i;
            }

            st.push(i);
        }

        return answer;
    }
};
