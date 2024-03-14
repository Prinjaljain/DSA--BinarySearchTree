#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
// Iterative Method
Node *insert(Node *root, int value)
{
    Node *temp = new Node(value);
    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->data < value)
        {
            curr = curr->right;
        }
        else if (curr->data > value)
        {
            curr = curr->left;
        }
        else
        {
            return root;
        }
    }
    if (parent == NULL)
    {
        return temp;
    }
    else if (parent->data < value)
    {
        parent->right = temp;
    }
    else
    {
        parent->left = temp;
    }
    return root;
}

// Recursive Method
//  Node *insert(Node *root, int value)
//  {
//      Node *temp = new Node(value);
//      if (root == NULL)
//      {
//          return temp;
//      }

//     if (root->data < value)
//     {
//         root->right = insert(root->right, value);
//     }
//     else
//     {
//         root->left = insert(root->left, value);
//     }
//     return root;
// }
void printTree(Node *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    insert(root, 62);
    printTree(root);
}