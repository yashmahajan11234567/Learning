#include <iostream>
#include <queue>
using namespace std;

class Node {
public: 
      int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
          left = right = nullptr;
    }
};

Node* InsertNode(Node* root, int data) {

    if (root == nullptr) {
        root = new Node(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* curr = q.front();
        q.pop();

        if (curr->left != nullptr)
            q.push(curr->left);
        else {
            curr->left = new Node(data);
            return root;
        }
    
        if (curr->right != nullptr)
            q.push(curr->right);
        else {
            curr->right = new Node(data);
            return root;
        }
    }
}

void inorder(Node* curr) {
    if (curr == nullptr)
        return;
    inorder(curr->left);
    cout << curr->data << ' ';
    inorder(curr->right);
}

int main() {

    Node* root = new Node(10);
    root->left = new Node(11);
      root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
  
    int key = 12;
    root = InsertNode(root, key);

    inorder(root);

    return 0;
}