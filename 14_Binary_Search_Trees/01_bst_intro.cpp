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
Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }

    return root;
}

// Build BST from an array
Node *buildTree(int arr[], int size)
{
    Node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = insertNode(root, arr[i]);
    }
    return root;
}

Node *deleteNode(Node *root, int key)
{
    // BASE CASE: Reached the end of a branch, target not found
    if (root == NULL)
    {
        cout << "No node to delete" << endl;
        return NULL;
    }

    // SEARCH PHASE: Traverse left or right based on BST property
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    // TARGET ACQUIRED: root->data == key
    else
    {
        // Case 1: Leaf Node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: One child Node
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two child Node
        else
        {
            Node *succ = root->right;
            while (succ->left != NULL)
            {
                succ = succ->left;
            }
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
            return root;
        }
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

    cout << "Is 5 exist in the tree: " << search(root, 5) << endl;

    insertNode(root, 25);

    cout << "Before deletion: ";
    inorder(root);
    cout << endl;

    deleteNode(root, -5);
    deleteNode(root, 34);

    cout << "After deletion: ";
    inorder(root);
    cout << endl;

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