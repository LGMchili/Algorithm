#include <iostream>
using namespace std;
int add(int x, int y){
    int sum, carry;
    do{
        sum = x ^ y; // get sum
        carry = (x & y) << 1; // get carry
        x = sum;
        y = carry;
    } while(y);
    return sum;
}
string countOne(int x){
    string res;
    for(int i = 0, b = 1; i < 32; i++, b <<= 1){
        if(x & b) res += "1";
        else res += "0";
    }
    int l = 0, r = res.size() - 1;
    while(l < r) swap(res[l++], res[r--]);
    return res;
}
int main(){
    int x = -3, y = 10; // TODO: why negative numbers are supported?
    int res = add(x, y);
    cout << countOne(15) << endl;
    cout << res << endl;
    return 0;
}
