#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValidParenthesis(string str){
        stack<char> st;

        for(int i = 0; i < str.size(); i++){

            // opening brackets
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            }
            else {
                // closing bracket but stack empty
                if(st.empty()){
                    return false;
                }

                char top = st.top();

                // matching pairs
                if((top == '(' && str[i] == ')') ||
                   (top == '{' && str[i] == '}') ||
                   (top == '[' && str[i] == ']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        // if stack empty → valid
        return st.empty();
    }
};

int main() {
    Solution sol;

    string input = "({})";

    bool ans = sol.isValidParenthesis(input);

    if(ans)
        cout << "Valid Parenthesis" << endl;
    else
        cout << "Invalid Parenthesis" << endl;

    return 0;
}
