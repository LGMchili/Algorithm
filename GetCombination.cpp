#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > res;

void helper(vector<vector<int>>& res, vector<int>& temp, int start, int n, int k){
    if(!k){
        res.push_back(temp);
        return;
    }
    for(int i = start; i < n; i++){
        temp.push_back(i);
        helper(res, temp, i + 1, n, k - 1);
        temp.pop_back();
    }
}
// get combination, select k numbers out of n numbers
int main(){
    vector<int> nums = {1,2,3,4,5}, temp;
    int k = 4;
    vector<vector<int>> res;
    helper(res, temp, 0, nums.size(), k);
    cout << res.size() << endl;
    for(auto x : res){
        for(auto y : x)
            cout << y << ' ';
        cout << endl;
    }
    return 0;
}
