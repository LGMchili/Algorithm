#include <iostream>
using namespace std;
int main(){
    int m, n;
    m = 2;
    n = 5;
    if(n == 0){
        cout << 1 << endl;
        return 0;
    }
    int res = m % 1000;
    for(int i = 1; i < n; i++){
        res *= m;
        res %= 1000;
    }
    cout << res << endl;
}
