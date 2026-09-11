#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL; // Leaf default state
    }
};

void inorder(Node *root)
{
    if (root == NULL) return; // Base case: end of branch
    
    inorder(root->left);       // Left
    cout << root->data << " "; // Root
    inorder(root->right);      // Right
}

void preorder(Node *root)
{
    if (root == NULL) return;
    
    cout << root->data << " "; // Root
    preorder(root->left);      // Left
    preorder(root->right);     // Right
}

void postorder(Node *root)
{
    if (root == NULL) return;
    
    postorder(root->left);     // Left
    postorder(root->right);    // Right
    cout << root->data << " "; // Root
}

int main()
{
    // Build root and attach branch and leaf
    Node *root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}