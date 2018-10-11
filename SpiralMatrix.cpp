#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& matrix){
    vector<int> res;
    int rowBegin = 0, colBegin = 0;
    int rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;
    while(rowBegin <= rowEnd && colBegin <= colEnd){
        for(int i = colBegin; i <= colEnd; i++)
            res.push_back(matrix[rowBegin][i]);
        rowBegin++;
        for(int i = rowBegin; i <= rowEnd; i++)
            res.push_back(matrix[i][colEnd]);
        colEnd--;
        // rowBegin and colEnd is changed in previous lines, thus need to check it again
        if(rowBegin <= rowEnd)
            for(int i = colEnd; i >= colBegin; i--)
                res.push_back(matrix[rowEnd][i]);
        rowEnd--;
        if(colBegin <= colEnd)
            for(int i = rowEnd; i >= rowBegin; i--)
                res.push_back(matrix[i][colBegin]);
        colBegin++;
    }
    return res;
}

int main(){
    vector<vector<int>> vec = {{1,2,3,4},
                               {1,2,3,4},
                               {1,2,3,4}};
    vector<int> res = spiralMatrix(vec);
    for(auto elem : res)
        cout << elem << ' ';
    cout << endl;
    return 0;
}
