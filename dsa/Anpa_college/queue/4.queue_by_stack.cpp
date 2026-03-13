#include <iostream>
#include <stack>
using namespace std;

class MyStack {
public:
    stack<int> s1;
    stack<int> s2;

    MyStack() {}

    void push(int data) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() {
        if (s1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyStack st;   // ✅ fixed

    st.push(10);
    st.push(20);
    st.push(30);


    cout << "Top element: " << st.peek() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    if (!st.empty()) {
        cout << "Top after pops: " << st.peek() << endl;
    }

    st.pop();
    st.pop();   // Underflow case

    return 0;
}




// #include <iostream>
// #include <queue>
// using namespace std;

// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;

//     MyStack() {}

//     void push(int data) {
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         q1.push(data);

//         while (!q2.empty()) {
//             q1.push(q2.front());
//             q2.pop();
//         }
//     }

//     int pop() {
//         if (q1.empty()) {
//             cout << "Stack Underflow!\n";
//             return -1;
//         }
//         int ans = q1.front();
//         q1.pop();
//         return ans;
//     }

//     int top() {
//         if (q1.empty()) {
//             cout << "Stack is empty!\n";
//             return -1;
//         }
//         return q1.front();
//     }

//     bool empty() {
//         return q1.empty();
//     }
// };

// int main() {
//     MyStack st;   // ✅ fixed

//     st.push(10);
//     st.push(20);
//     st.push(30);


//     cout << "Top element: " << st.top() << endl;

//     cout << "Popped: " << st.pop() << endl;
//     cout << "Popped: " << st.pop() << endl;

//     if (!st.empty()) {
//         cout << "Top after pops: " << st.top() << endl;
//     }

//     st.pop();
//     st.pop();   // Underflow case

//     return 0;
// }
