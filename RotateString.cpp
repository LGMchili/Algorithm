#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
vector<string> rotateString(string s){
    stringstream st(s);
    string temp;
    vector<string> res;
    while(st >> temp){
        res.push_back(temp);
    }
    int l = 0, r = res.size() - 1;
    while(l < r)
        swap(res[l++], res[r--]);
    return res;
}

int main(){
    string str = "I am a student.";
    vector<string> res = rotateString(str);
    for(auto s : res)
        cout << s << endl;
    return 0;
}
