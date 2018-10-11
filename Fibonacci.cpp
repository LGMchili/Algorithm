#include <iostream>
using namespace std;

int fibo(int n){
    if(n <= 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

int o1fibo(int n){
    if(n <= 1)
        return n;
    int prev = 1, pprev = 0, res;
    for(int i = 2; i <= n; i++){
        res = prev + pprev;
        pprev = prev;
        prev = res;
    }
    return res;
}

int main(){
    int n = 8;
    cout << o1fibo(n) << endl;
    return 0;
}
