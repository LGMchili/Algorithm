#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
    list<int> window;
    int k = 3;
    vector<int> nums = {1,14,3,4,15,66,3,0,2,10};
    for(int i = 0; i < nums.size(); i++){
        while(!window.empty() && nums[window.back()] < nums[i]) window.pop_back();
        window.push_back(i);
        if(i >= k - 1) cout << nums[window.front()] << ' ';
        if(window.front() == i - k + 1) window.pop_front();
    }
    cout << endl;
    return 1;
}
