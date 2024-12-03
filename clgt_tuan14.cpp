#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isEmpty(Node* root) {
    return root == nullptr;
}

Node* insert(Node* root, char data) {
    if (root == nullptr) {
        return new Node(data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node* createExpressionTree() {
    Node* root = new Node('+');
    root->left = new Node('-');
    root->left->left = new Node('*');
    root->left->left->left = new Node('a');
    root->left->left->right = new Node('5');
    root->left->right = new Node('/');
    root->left->right->left = new Node('*');
    root->left->right->left->left = new Node('b');
    root->left->right->left->right = new Node('^');
    root->left->right->left->right->left = new Node('c');
    root->left->right->left->right->right = new Node('6');
    root->left->right->right = new Node('d');
    root->right = new Node('*');
    root->right->left = new Node('-');
    root->right->left->left = new Node('h');
    root->right->left->right = new Node('f');
    root->right->right = new Node('^');
    root->right->right->left = new Node('e');
    root->right->right->right = new Node('1');
    return root;
}

int main() {
    Node* root = createExpressionTree();

    cout << "Infix: ";
    inorder(root);
    cout << endl;

    cout << "Postfix: ";
    postorder(root);
    cout << endl;

    cout << "Prefix: ";
    preorder(root);
    cout << endl;

    return 0;
}
