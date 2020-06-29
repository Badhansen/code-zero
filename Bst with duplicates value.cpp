// AC
#include<iostream>

using namespace std;

#define NULL 0

typedef struct Node{
    int value;
    int count;
    Node *left, *right;
    Node(){
        value = count = 0;
        left = right = NULL;
    }
    Node(int val){
        value = val;
        count = 1;
        left = right = NULL;
    }
}Node;

Node* add(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val == root->value){
        (root->count)++;
        return root;
    }
    if(val < root->value){
        root->left = add(root->left, val);
    }
    else{
        root->right = add(root->right, val);
    }
    return root;
}
Node* minValueNode(Node* root){
    Node* curr = root;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
Node* deleteNode(Node* root, int val){
    if(root == NULL)
        return NULL;
    if(val < root->value){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->value){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->count > 1){
            (root->count)--;
            return root;
        }
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}
int find(Node* root, int val){
    if(root == NULL){
        return -1;
    }
    if(root->value == val){
        return root->count;
    }
    if(val < root->value){
        return find(root->left, val);
    }
    else{
        return find(root->right, val);
    }
}
void inorder(Node *root){ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->value << "("
             << root->count << ") "; 
        inorder(root->right); 
    } 
} 
int main()
{
    Node *root = NULL; 
    root = add(root, 12); 
    root = add(root, 10); 
    root = add(root, 20); 
    root = add(root, 9); 
    root = add(root, 11); 
    root = add(root, 10); 
    root = add(root, 12); 
    root = add(root, 12); 

    cout << "Inorder traversal of the given tree " 
         << endl; 
    inorder(root); 
  
    cout << "\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 12\n" ; 
    root = deleteNode(root, 12); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 9\n"; 
    root = deleteNode(root, 9); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 

    return 0;
}