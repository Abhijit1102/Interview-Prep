#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;      // stores indices
        vector<int> res;

        // First window
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Remaining windows
        for(int i = k; i < nums.size(); i++) {

            // Add max of previous window
            res.push_back(nums[dq.front()]);

            // Remove elements not in current window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Add max of last window
        res.push_back(nums[dq.front()]);

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(nums, k);

    cout << "Result: ";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
