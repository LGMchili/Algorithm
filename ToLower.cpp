#include <iostream>
#include <string>
using namespace std;

string toLower(string& s){
    for(char& cr : s){
        if(cr <= 'Z' && cr >= 'A'){
            // add difference between upper and lower letter
            // 'Z' - 'z' = -32
            cr -= ('Z' - 'z');
        }
    }
    return s;
}

int main(){
    string s = "Hello World";
    cout << s << endl;
    toLower(s);
    cout << s << endl;
    return 0;
}
