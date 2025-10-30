#include <iostream>
using namespace std;

class MinStack {
private:
    int stack[1000];     // main stack
    int minstack[1000];  // stack to track minimums
    int topindex;        // for main stack
    int mintopindex;     // for min stack

public:
    MinStack() {
        topindex = -1;
        mintopindex  = -1;
    }

    void push(int val) {
        if (topindex < 999) {
            stack[topindex++] = val;

            if (mintopindex == -1 || val <= minstack[mintopindex])
                minstack[mintopindex++] = val;
        } else {
            cout << "Stack Overflow"<<endl;
        }
    }

    void pop() {
        if (topindex == -1) {
            cout << "Stack Underflow"<<endl;
            return;
        }

        int popped = stack[topindex--];

        if (mintopindex != -1 && popped == minstack[mintopindex])
            mintopindex--;
    }

    int top() {
        if (topindex == -1) {
            cout << "Stack is empty"<<endl;
            return -1;
        }
        return stack[topindex];
    }

    int getMin() {
        if (mintopindex == -1) {
            cout << "Stack is empty"<<endl;
            return -1;
        }
        return minstack[mintopindex];
    }
};

int main() {
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    cout << "Min: " << st.getMin() << endl; 
    st.pop();
    cout << "Top: " << st.top() << endl;     
    cout << "Min: " << st.getMin() << endl;  
    st.pop();
    cout << "Min: " << st.getMin() << endl; 
    return 0;
}
