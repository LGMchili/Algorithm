#include <iostream>
#include <string>
#include <vector>
using namespace std;

void helper(vector<int> nums, vector<vector<int> >& res, int start){
    if(start >= nums.size()){
        res.push_back(nums);
    }
    for(int i = start; i < nums.size(); i++){
        swap(nums[start], nums[i]);
        // select the ith(start) number, then go to
        helper(nums, res, start + 1);
        swap(nums[start], nums[i]);
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res;
    helper(nums, res, 0);
    for(auto r : res){
        for(auto c : r)
            cout << c << ' ';
        cout << endl;
    }

    return 0;
}
