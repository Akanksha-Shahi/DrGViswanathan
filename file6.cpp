// MIN STACK
#include<bits/stdc++.h>
using namespace std;
class MinStack {
    stack<long> st;
    long long mini;
public:
    MinStack() {
        mini =  LONG_MAX;
    }
    
    void push(int val) {
        if( st.empty()) {
            mini =val;
            st.push(val);
        }
        else if( val>= mini ) st.push(val);
        else{
            st.push(2LL *val-mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long n = st.top();
        st.pop();
        if( n< mini ) mini =2LL *mini -n;
    }
    
    int top() {
        if( st.empty()) return -1;
        long long n = st.top();
        if ( mini <= n) return (int)n;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
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
