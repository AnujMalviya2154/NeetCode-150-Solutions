class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {}

    void push(int val) {

        if(st.empty()) {

            st.push(val);
            mini = val;
        }

        else if(val >= mini) {

            st.push(val);
        }

        else {

            long long encoded = 2LL * val - mini;
            st.push(encoded);
            mini = val;
        }
    }

    void pop() {

        if(st.empty()) return;

        if(st.top() < mini) {

            mini = 2 * mini - st.top();
        }

        st.pop();
    }

    int top() {

        if(st.top() < mini)
            return mini;

        return st.top();
    }

    int getMin() {

        return mini;
    }
};