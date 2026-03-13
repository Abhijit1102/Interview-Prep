#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for(int i = 2*n - 1; i >= 0; i--) {

            while(!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }

            if(i < n) {  // only fill answer in first pass
                ans[i] = s.empty() ? -1 : nums[s.top()];
            }

            s.push(i % n);
        }

        return ans;
    }
};

int main(){

    vector<int> nums = {1, 2, 1};

    Solution obj;

    vector<int> ans = obj.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
