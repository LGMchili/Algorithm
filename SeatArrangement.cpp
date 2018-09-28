#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct compare{
    bool operator()(pair<char, int>& a, pair<char, int>& b) const {
        return a > b;
    }
};

string seatArrangement(string s, int k){
    vector<pair<char, int>> sorted;
    string res;
    int  maxVal = 0;
    map<char, int> mp;
    priority_queue<int> pq;
    for(auto c : s){
        mp[c]++;
        maxVal = max(maxVal, mp[c]);
    }
    for(auto& val : mp){
        sorted.push_back(val);
    }
    sort(sorted.begin(), sorted.end(), [](pair<char, int>& a, pair<char, int>& b){
        return a.second > b.second;
    });
    int size = mp.size();
    while(size > 0){
        if(size <= k && maxVal > 1){
            // can not arrange then in the last loop
            cout << "-1" << endl;
            return 0;
        }
        for(auto& val : sorted){
            if(val.second != 0){
                res += val.first;
                val.second--;
                if(val.second == 0)
                    size--;
            }
        }
        maxVal--;
    }
    cout << res << endl;
    return res;
}

int main(){
    // TODO:
    string s = "aaaabbbbccccdddddeeefffgghh";
    int k = 2;
    seatArrangement(s, k);
    return 0;
}
