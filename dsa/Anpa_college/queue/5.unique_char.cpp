#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqueChar(string s) {
        unordered_map<char, int> m;
        queue<int> Q;

        for(int i = 0; i < s.size(); i++) {
            if(m.find(s[i]) == m.end()) {
                Q.push(i);
            }

            m[s[i]]++;

            while(!Q.empty() && m[s[Q.front()]] > 1) {
                Q.pop();
            }
        }

        if(Q.empty())
            return -1;

        return Q.front();
    }
};

int main() {
    Solution obj;
    string s = "leetcode";
    cout << "Result : \n" << endl;
    cout << obj.firstUniqueChar(s) << endl;
    return 0;
}
