#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mystoi(string s){
    int m = s.size();
    int sign = 1, num = 0;
    for(int i = 0; i < m; i++){
        if(s[i] == '-')
            sign = -1;
        if('0' <= s[i] && s[i] <= '9'){
            num = num * 10 + (s[i] - '0');
        }
    }
    return num * sign;
}

int myatoi(const char* s){
    int sign = 1, num = 0, index = 0;
    while(*(s + index)){
        char ch = *(s + index);
        if(ch == '-')
            sign = -1;
        if('0' <= ch && ch <= '9'){
            num = num * 10 + (ch - '0');
        }
        index++;
    }
    return num * sign;
}

int main(){
    string s = "-0000001024";
    const char* c = "-0000001024";
    int i = mystoi(s);
    int j = myatoi(c);
    cout << "myatoi result: " << i << endl;
    cout << "mystoi result: " << j << endl;
    return 0;
}
