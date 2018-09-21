#include <iostream>
#include <vector>
int main(){
    int num = 5;
    std::vector<int> res(num+1, 0);
    // two methods

    // dynamic programming, can get any 1 bit counts less than num
    res[0] = 0;
    for(int i = 1; i <= num; i++){
        res[i] = res[i&(i-1)] + 1; // remove rightmost bit of 1
    }
    // check every bits
    int temp = 1, ans = 0;
    for(int j = 0; j < 32; j++){
        if(num & temp)
            ans++;
        temp <<= 1;
    }
    std::cout << res[num] << std::endl;
    std::cout << ans << std::endl;
    return 0;
}
