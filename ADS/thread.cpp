#include<iostream>
#include<cstdlib>
#define MAX_VALUE 65536
using namespace std;

class node {
public:
    int key;
    node* left;
    node* right;
    bool leftThread, rightThread;
};

class ThreadedBinaryTree {
private:
    node* root;
public:
    ThreadedBinaryTree() {
        root = new node();
        root->right = root->left = root;
        root->leftThread = true;
        root->key = MAX_VALUE;
    }

    void makeEmpty() {
        root = new node();
        root->right = root->left = root;
        root->leftThread = true;
        root->key = MAX_VALUE;
    }

    void insert(int key) {
        node* current = root;
        while (true) {
            if (current->key < key) {
                if (current->rightThread) break;
                current = current->right;
            } else if (current->key > key) {
                if (current->leftThread) break;
                current = current->left;
            } else {
                return;
            }
        }

        node* newnode = new node();
        newnode->key = key;
        newnode->leftThread = newnode->rightThread = true;

        if (current->key < key) {
            newnode->right = current->right;
            newnode->left = current;
            current->right = newnode;
            current->rightThread = false;
        } else {
            newnode->left = current->left;
            newnode->right = current;
            current->left = newnode;
            current->leftThread = false;
        }
    }

    bool search(int key) {
        node* current = root->left;
        while (true) {
            if (current->key < key) {
                if (current->rightThread) return false;
                current = current->right;
            } else if (current->key > key) {
                if (current->leftThread) return false;
                current = current->left;
            } else {
                return true;
            }
        }
    }

    void deleteNode(int key) {
        node* parent = root;
        node* currentNode = root->left;

        while (true) {
            if (currentNode->key < key) {
                if (currentNode->rightThread) return;
                parent = currentNode;
                currentNode = currentNode->right;
            } else if (currentNode->key > key) {
                if (currentNode->leftThread) return;
                parent = currentNode;
                currentNode = currentNode->left;
            } else {
                break; // found the node to delete
            }
        }

        node* targetNode = currentNode;

        if (targetNode->leftThread && targetNode->rightThread) {
            // Node is a leaf
            if (parent->right == targetNode) parent->right = targetNode->right;
            else parent->left = targetNode->left;
            delete targetNode;
        } else if (!targetNode->leftThread && !targetNode->rightThread) {
            // Node has two children
            node* successor = targetNode->left;
            while (!successor->rightThread) successor = successor->right;
            targetNode->key = successor->key;
            deleteNode(successor->key);
        } else {
            // Node has one child
            node* child = targetNode->leftThread ? targetNode->right : targetNode->left;
            if (parent->right == targetNode) parent->right = child;
            else parent->left = child;
            delete targetNode;
        }
    }

    void displayTree() {
        node* currentNode = root->right;
        while (currentNode != root) {
            cout << currentNode->key << " ";
            currentNode = currentNode->right;
            while (!currentNode->leftThread) currentNode = currentNode->left;
        }
        cout << endl;
    }
};

int main() {
    ThreadedBinaryTree tree;
    cout << "Threaded Binary Tree\n";

    int choice, value;

    while (true) {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << "Element found in the tree\n";
                } else {
                    cout << "Element not found in the tree\n";
                }
                break;

            case 4:
                cout << "Tree elements: ";
                tree.displayTree();
                break;

            case 5:
                exit(0);

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

