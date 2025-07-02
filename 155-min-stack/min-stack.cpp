class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        while(!st.empty()) st.pop();
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if(val < mini) {
                st.push(2LL * val - mini);  // Encode
                mini = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if(topVal < mini) {
            mini = 2LL * mini - topVal;  // Decode previous min
        }
    }
    
    int top() {
        long long topVal = st.top();
        if(topVal < mini) {
            return mini;  // Top is encoded => actual top is mini
        } else {
            return topVal;
        }
    }
    
    int getMin() {
        return mini;
    }
};
