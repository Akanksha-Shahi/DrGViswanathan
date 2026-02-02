// MIN STACK
#include<bits/stdc++.h>
using namespace std;
class MinStack {
    stack<long> st;
    int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if( st.empty()) {
            mini =val;
            st.push(val);
        }
        else if( val> mini ) st.push(val);
        else{
            st.push(2*val-mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        int n = st.top();
        st.pop();
        if( n< mini ) mini =2*mini -n;
    }
    
    int top() {
        if( st.empty()) return -1;
        int n = st.top();
        if ( mini<n) return n;
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */