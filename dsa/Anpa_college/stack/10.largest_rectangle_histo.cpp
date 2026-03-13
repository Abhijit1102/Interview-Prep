#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
public:
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;

        // Next Smaller to Right
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Clear stack
        while(!s.empty()){
            s.pop();
        }

        // Next Smaller to Left
        for(int i = 0; i < n; i++) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }

        return ans;
    }
};

int main() {

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    Solution obj;

    int area = obj.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << area << endl;

    return 0;
}
