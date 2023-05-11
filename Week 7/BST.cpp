#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create Node
struct node* createNode(int val) {
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->key = val;
  temp->left = nullptr;
  temp->right = nullptr; 
  return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root != nullptr) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == nullptr) {
    return createNode(key);
  }

  if(key < node->key) {
    node->left = insertNode(node->left, key);
  }
  else if(key > node->key) {
    node->right = insertNode(node->right, key);
  }
  return node;


}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == nullptr) 
    return root;
  
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }
  else {      //if key match with the value of the key.
     // Case 1: If the node has no children
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr;
    }
    // Case 2: If the node has one child
    else if (root->left == nullptr) {
      struct node *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == nullptr) {
      struct node *temp = root;
      root = root->left;
      delete temp;
    }
    // Case 3: If the node has two children
    else {
      struct node *temp = root->right;
      while (temp->left != nullptr) {
        temp = temp->left;
      }
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
