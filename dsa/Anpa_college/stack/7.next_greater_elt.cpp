#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {

        unordered_map<int, int> m;
        stack<int> s;

        // Build map using nums2
        for(int i = nums2.size() - 1; i >= 0; i--) {

            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            if(s.empty()) {
                m[nums2[i]] = -1;
            }
            else {
                m[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        // Answer for nums1
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};

int main() {

    vector<int> nums1 = {2,4,5};
    vector<int> nums2 = {1,2,3,4,5,6};

    Solution obj;
    vector<int> result = obj.nextGreaterElement(nums1, nums2);

    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
