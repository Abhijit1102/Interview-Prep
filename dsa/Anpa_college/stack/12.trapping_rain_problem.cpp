#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height){
        int n = height.size();
        int ans = 0;
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;

        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }
            else {
                ans += rmax - height[r];
                r--;   // ⭐ VERY IMPORTANT (missing line)
            }
        }
        return ans;
    }
};

int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution obj;

    int water = obj.trap(height);

    cout << "Trapped Water: " << water << endl;

    return 0;
}
