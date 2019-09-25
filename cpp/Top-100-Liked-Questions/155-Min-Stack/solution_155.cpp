/*
 * 155. Min Stack
 */


#include "common.h"


#if LEET_CODE == 155

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        st1.push(x);
        if (st2.empty() || x <= st2.top())
            st2.push(x);
    }

    void pop() {
        if (st1.top() == st2.top())
            st2.pop();
        st1.pop();
        // if (!st1.empty() && (st2.empty() || st1.top() < st2.top()))
        //     st2.push(st1.top());
    }

    int top() {
        return st1.empty() ? -1 : st1.top();
    }

    int getMin() {
        return st2.empty() ? -1 : st2.top();
    }

private:
    stack<int> st1, st2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    cout << "155. Min Stack" << endl;

    return 0;
}


#endif
