#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int main(){
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int> > prev, res;
    for(int num : nums){
        // get combinations end with num
        // nums[i]
        // prev is the combinations end with nums[i-1]
        for(auto& vec : prev){
            vec.push_back(num);
        }
        prev.push_back({num});
        // override prev, otherwise, it would form discontinuous combinations
        // add new combinations which end with num to result
        for(auto& c : prev){
            res.push_back(c);
        }
    }
    // debug
    for(auto vec : res){
        for(auto val : vec)
            cout << val << ' ';
        cout << endl;
    }
    return 0;
}
