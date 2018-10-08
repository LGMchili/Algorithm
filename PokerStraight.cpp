#include <iostream>
#include <vector>
using namespace std;

bool isStraight(vector<int>& cards){
    sort(cards.begin(), cards.end());
    int dif = 0, zeros = 0;
    for(int i = 0; i < cards.size() - 1; i++){
        if(cards[i] == 0){
            zeros++; // joker的数量
            continue;
        }
        int diff = cards[i+1] - cards[i];
        if(!diff) return false; // 对子
        dif += diff - 1; // 不连续的牌中间差几张
    }
    return dif <= zeros;
}

int main(){
    vector<int> cards = {1,4,5,0,0};
    bool res = isStraight(cards);
    cout << res << endl;
    return 0;
}
