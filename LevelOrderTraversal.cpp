#include <queue>
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int v): val(v){
        left = NULL;
        right = NULL;
    }
};
void levelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* t = q.front();
            cout << t->val << ' ';
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            q.pop();
        }
    }
    cout << endl;
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(7);
    levelOrder(root);
}
