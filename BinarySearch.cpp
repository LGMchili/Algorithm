#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1,3,5,8,9,23,75,80,100,120,129};
    int l = 0, r = vec.size(), mid;
    int tar = 74;
    while(l <= r){
        mid = (l + r) / 2;
        if(vec[mid] == tar){
            cout << "found" << endl;
            return 0;
        }
        if(vec[mid] < tar)
            l = mid + 1;
        else if(vec[mid] > tar)
            r = mid - 1;
    }
    cout << "failed" << endl;
    return 0;
}
