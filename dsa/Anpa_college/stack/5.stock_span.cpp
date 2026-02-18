#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> stock_span(vector<int> price){

        vector<int> ans(price.size(), 0);   // correct vector initialization
        stack<int> s;   // stack stores INDEXES (not prices)

        for(int i = 0; i < price.size(); i++) {

            // pop all smaller or equal prices
            while(!s.empty() && price[s.top()] <= price[i]){
                s.pop();
            }

            // if no greater element on left
            if(s.empty()){
                ans[i] = i + 1;
            }
            else{
                ans[i] = i - s.top();
            }

            s.push(i);
        }

        return ans;
    }
};

int main(){

    // Stock price
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    Solution sol;
    vector<int> result = sol.stock_span(price);

    cout << "Stock Span: " << endl;
    for(int x : result){
        cout << x << " " << endl;
    }

    return 0;
}
