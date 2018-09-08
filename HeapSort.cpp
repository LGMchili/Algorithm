#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& A, int i, int len){
    int l = 2*i;
    int r = l + 1;
    int largest = i;
    if(l <= len && A[i-1] < A[l-1])
        largest = l;
    if(r <= len && A[largest-1] < A[r-1])
        largest = r;
    if(largest != i){
        swap(A[i-1], A[largest-1]);
        heapify(A, largest, len); // heapify the child tree
    }
}

void build(vector<int>& A){
    int size = A.size();
    // make sure evey subtree is max heap
    for(int i = size/2; i > 0; i--){
        heapify(A, i, size);
    }
}
void heapSort(vector<int>& A){
    int len = A.size();
    for (int i = len; i > 1; --i)
    {
        swap(A[0], A[i-1]);
        heapify(A, 1, --len);
    }
}

int main(){
    vector<int> A{3,5,6,7,7,3,2,23,5,123,345,56,87,1,2,45,7};
    build(A);
    heapSort(A);
    for(auto val : A)
        cout << val << ' ';
    cout << endl;
    return 0;
}
