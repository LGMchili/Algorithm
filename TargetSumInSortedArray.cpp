#include <vector>
#include <iostream>
using namespace std;
pair<int, int> targetSum(const vector<int>& A, int tar){
    int l = 0, r = A.size() - 1;
    while(l < r){
        int x = A[l], y = A[r];
        if(x + y == tar) return make_pair(x, y);
        else if(x + y < tar) l++;
        else r--;
    }
    return make_pair(-1, -1);
}

int main(){
    vector<int> A = {1,2,3,4,5,6,7,8,9,10};
    int target = 10;
    pair<int, int> res = targetSum(A, target);
    cout << res.first << ", " << res.second << endl;
    return 0;
}
