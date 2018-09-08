#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& A, int l, int r){
    int i = l - 1;
    int x = A[r];
    for(int j = l; j < r; j++){
        if(A[j] < x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[r], A[i+1]);
    return i + 1;
}

void quickSort(vector<int>& A, int l, int r){
    if(l >= r)
        return;
    int q = partition(A, l, r);
    quickSort(A, l, q - 1);
    quickSort(A, q + 1, r);
}


int main(){
    vector<int> A{3,5,6,7,7,3,2,23,5,123,345,56,87,1,2,45,7};
    quickSort(A, 0, A.size() - 1);
    for(auto val : A)
        cout << val << ' ';
    cout << endl;
    return 0;
}
