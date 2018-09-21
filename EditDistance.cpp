#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<int> cur(m + 1, 0);
    for (int i = 1; i <= m; i++)
        cur[i] = i;
    for (int j = 1; j <= n; j++) {
        int pre = cur[0];
        cur[0] = j;
        for (int i = 1; i <= m; i++) {
            int temp = cur[i];
            if (word1[i - 1] == word2[j - 1])
                cur[i] = pre;
            else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
            pre = temp;
        }
    }
    return cur[m];
}

int main() {
    vector<string> words;
    vector<pair<int, int>> res;
    string word;
    string target;
    while(cin >> word)
        words.push_back(word);
    target = words[0];
    words.erase(words.begin());
    //int dis = 2147483647;
    int index = 0;
    for(string w : words){
        int dis = minDistance(w, target);
        res.push_back(make_pair(dis, index));
        index++;
    }
    auto func = [](pair<int, int> p1, pair<int, int> p2){
        if(p1.first == p2.first)
            return p1.second < p2.second;
        else
            return p1.first < p2.first;
    };
    sort(res.begin(), res.end(), func);
    for(int i = 0; i < 3; i++){
        cout << words[res[i].second] << ' ';
    }
    cout << endl;
    return 0;
}
