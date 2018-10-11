#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v): val(v){
        next = NULL;
    }
};

void findKthToTail(Node* head, int k){
    Node* node = head;
    while(k--) node = node->next;
    while(node){
        head = head->next;
        node = node->next;
    }
    cout << head->val << endl;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    findKthToTail(n1, 5);
    return 0;
}
