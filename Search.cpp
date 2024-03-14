#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};
// Iterative Method [time complexity:- O(h) but auxillary space is O(1)]
bool search(Node*root,int value){
    while(root!=NULL){
        if(root->data==value){
            return true;
        }
        if(root->data>value){
            root=root->left;
        }
        if(root->data<value){
            root=root->right;
        }
    }
    return false;
}
// Recursive Method [time complexity:- O(h) but auxillary space is O(h)]
//  bool search(Node *root, int value)
//  {
//      if (root == NULL)
//      {
//          return false;
//      }
//      if (root->data == value)
//      {
//          return true;
//      }
//      else if (root->data < value)
//      {
//          return search(root->right, value);
//      }
//      else
//      {
//          return search(root->left, value);
//      }
//      return false;
//  }
int main()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    cout << search(root, 16);
    return 0;
}