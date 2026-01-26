#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    
    node(int val){
        data = val;
        left = right = nullptr;
    }

};

int countLeaves(node* root){

    if(root == nullptr){
    return 0;
    }

    if(root -> left == nullptr && root -> right == nullptr){
    return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int main(){
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7); 

    cout << countLeaves(root) << " ";

    return 0;
}