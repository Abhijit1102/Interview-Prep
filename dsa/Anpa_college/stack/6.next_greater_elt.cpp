#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> arr){

        stack<int> s;                     // stack stores elements
        vector<int> ans(arr.size(), 0);

        // traverse from right
        for(int i = arr.size() - 1; i >= 0; i--){

            // remove smaller elements
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }

            // if no greater element
            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }

            // push current element
            s.push(arr[i]);
        }

        return ans;
    }
};

int main(){

    vector<int> arr = {6, 8, 0, 3};

    Solution sol;
    vector<int> result = sol.nextGreaterElement(arr);

    cout << "Result: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
