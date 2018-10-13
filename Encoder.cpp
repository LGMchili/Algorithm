#include <iostream>
using namespace std;
void encoder(string s){
    string res;
    char t;
    int count = 0;
    t = s[0];
    for(int i = 0; i < s.size(); i++){
        if(t == s[i])
            count++;
        else{
            if(count > 1) res += to_string(count);
            res += t;
            t = s[i];
            count = 1;
        }
    }
    if(count > 1) res += to_string(count);
    res += t;
    cout << res << endl;
}
int main(){
    string s = "aaaaabbbbccdee";
    encoder(s);
}
