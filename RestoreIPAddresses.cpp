#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        vector<string> res;
        helper(s, 0, 0, ip, res);
        return res;
    }
    void helper(const string& s, int start, int step, string ip, vector<string>& res){
        if(step == 4){
            if(start == s.size()){
                ip.erase(ip.end() - 1); // remove the last '.'
                res.push_back(ip);
                _cnt++;
                return;
            }
            else
                return;
        }
        if(s.size() - start > (4 - step) * 3) return;
        if(s.size() - start < 4 - step) return;
        int num = 0;
        for(int i = start; i < start + 3 && i < s.size(); i++){
            cout << i << endl;
            num = num*10 + (s[i] - '0');
            if(num <= 255){
                ip += s[i];
                helper(s, i+1, step+1, ip+'.', res);
            }
        }
    }
    int _cnt = 0;
};

int main(){
    Solution solu;
    vector<string> ans;
    ans = solu.restoreIpAddresses("25525511135");
    for(auto val : ans)
        cout << val << endl;
    cout << solu._cnt << endl;
    return 0;
}
