#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct compare{
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};
int main(){
    // TODO:
    string s = "aaaabbbbccccddddd";
    int k = 2, maxVal = 0;
    string res;
    map<char, int, compare> mp;
    priority_queue<int> pq;
    for(auto c : s){
        mp[c]++;
        maxVal = max(maxVal, mp[c]);
    }
    for(auto& val : mp){
        cout << val.second << " " << val.first << endl;
    }
    int size = mp.size();
    while(size > 0){
        if(size <= k && maxVal > 1){
            // can not arrange then in the last loop
            cout << "-1" << endl;
            return 0;
        }
        for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
            if(it->second != 0){
                res += it->first;
                it->second--;
                if(it->second == 0)
                    size--;
            }
        }
        maxVal--;
    }
    cout << res << endl;
    return 0;
}
