#include <iostream>
#include <list>
using namespace std;

class Stack {
    list<int> v;

public:
    void push(int val){
        v.push_front(val);   // top at front
    }

    void pop(){
        if(!v.empty())
            v.pop_front();
    }

    int top(){
        if(v.empty()){
            cout << "Stack Underflow\n";
            return -1;
        }
        return v.front();   // CORRECT
    }

    bool empty() {
        return v.empty();   // better than size()==0
    }
};

int main(){
    Stack s;

    s.push(20);
    s.push(30);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
