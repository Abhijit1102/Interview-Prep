#include <iostream>
#include <stack>
using namespace std;

class MinStack{
public:
    stack<long long> s;
    long long minVal;

    MinStack(){}

    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minVal = val;
        }
        else {
            if(val < minVal) {
                // push encoded value
                s.push(2LL*val - minVal);
                minVal = val;
            }
            else {
                s.push(val);
            }
        }
    }

    void pop(){
        if(s.empty()) return;

        if(s.top() < minVal) {
            // encoded value -> restore previous min
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if(s.empty()) return -1;

        if(s.top() < minVal){
            return minVal; // actual value
        }
        else {
            return s.top();
        }
    }

    int getMin() {
        if(s.empty()) return -1;
        return minVal;
    }
};

int main() {
    MinStack ms;

    cout << "Pushing 5\n";
    ms.push(5);
    cout << "Current Min: " << ms.getMin() << endl;

    cout << "Pushing 3\n";
    ms.push(3);
    cout << "Current Min: " << ms.getMin() << endl;

    cout << "Pushing 7\n";
    ms.push(7);
    cout << "Current Min: " << ms.getMin() << endl;

    cout << "Top Element: " << ms.top() << endl;

    cout << "Popping top element\n";
    ms.pop();
    cout << "Top Element: " << ms.top() << endl;
    cout << "Current Min: " << ms.getMin() << endl;

    cout << "Popping top element\n";
    ms.pop();
    cout << "Top Element: " << ms.top() << endl;
    cout << "Current Min: " << ms.getMin() << endl;

    return 0;
}
