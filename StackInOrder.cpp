#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(){
    stack<TreeNode*> stk;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(7);
    // meet a new node, go to previous if not
    while(root || !stk.empty()){
        // push its left to stack
        while(root){
            stk.push(root);
            // cout << root->val << ' '; // preorder
            root = root->left;
        }
        // start from leftmost
        root = stk.top();
        stk.pop();
        cout << root->val << ' '; // inorder
        // then go to its right
        root = root->right;
    }
    cout << endl;
}
