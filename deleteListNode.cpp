#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v): val(v){
        next = NULL;
    }
};

void del(Node* node, Node** head){
    if(!node->next){
        Node* h = *head;
        if(node == h){
            // delete head;
            *head = NULL;
        }
        else{
            while(h->next != node) h = h->next;
            h->next = NULL;
        }
        delete node;
        return;
    }
    Node* temp = node->next;
    *node = *(node->next);
    delete temp;
}

void printList(Node* head){
    while(head){
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
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
    printList(n1);
    del(n1, &n1);
    printList(n1);
}
