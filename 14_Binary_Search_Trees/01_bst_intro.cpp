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
        left = right = NULL;
    }
};

// Recursively find the correct position and attach the new node
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Build BST from an array
Node *buildTree(int arr[], int size)
{
    Node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

bool search(Node *root, int key)
{
    // 1. CRITICAL: Check if node exists FIRST to prevent crashes
    if (root == NULL)
    {
        return false;
    }

    // 2. Check if we found the target
    if (root->data == key)
    {
        return true;
    }

    // 3. CATCH AND RETURN the result of the recursion!
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

// Left, Root, Right (sorted order)
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Root, Left, Right (Used for copying trees)
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Left, Right, Root (Used for deleting trees safely)
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int arr[] = {2, 5, 6, 23, 34, 1, -5};
    int size = 7;

    // Store the returned root of the fully constructed tree
    Node *root = buildTree(arr, size);

    cout << search(root, 5) << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);

    return 0;
}