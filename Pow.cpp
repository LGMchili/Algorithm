#include <iostream>

using namespace std;

double pow(int base, int exp){
    double res = 1;
    int p = (exp >= 0) ? exp : -exp;
    while(p){
        // additional multiplication if exp is an odd number
        if(p & 1)
            res *= base;
        p >>= 1;
        if(!p)
            break;
        base *= base;
    }
    return (exp >= 0) ? res : 1 / res;
}

int main(){
    int a = 2, b = 10;
    cout << pow(a,b) << endl;
    return 0;
}
