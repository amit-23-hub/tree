#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* insert(Node* root, int el) {
    // Base case
    if (!root) {
        Node* temp = new Node(el);
        return temp;
    }

    if (el < root->data) {
        root->left = insert(root->left, el);
    } else {
        root->right = insert(root->right, el);
    }

    return root;
} ; 

// print 
void inorder (Node* root){
    if(root == NULL){
        return ;
    }
    
    inorder(root->left) ; 
    cout<< root->data << " "  ;
     inorder(root->right) ; 
 }

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    Node* root = NULL;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        root = insert(root, arr[i]);
    }
    
    
    inorder(root) ;
    return 0;
}
