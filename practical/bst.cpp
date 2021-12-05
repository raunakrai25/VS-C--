#include<iostream>
using namespace std;

struct node {
    int info;
    struct node *left;
    struct node *right;
}*ptr, *root=NULL;

node *createNode(int n){
    ptr = new node;
    ptr ->info = n;
    ptr ->left=NULL;
    ptr ->right=NULL;
    return ptr;
}

void preorder(struct node *root){
    if (root != NULL){
         preorder(root->right);
        cout << root ->info << " ";
        preorder(root->left);
       
    }
}

void postorder(struct node *root){
    if (root != NULL){
        postorder(root->right);
        postorder(root->left);
        
        cout << root->info << " ";
    }
}

void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}

struct node* insertNode(struct node *node, int num){
    if (node == NULL){
        struct node *nn = createNode(num);
        if (root == NULL){
            root = nn;
        }
            return nn;
        }
        if (num < node->info)

            node->left = insertNode(node->left,num);
        else if (num > node->info)
            node->right = insertNode(node->right,num);
        return node;
    
}

int main (){

    int op, data;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
    {
        cout << "What operation you wanna performe : "<<"\n";
        cout << "press (1) to Insert Element\n" << "press (2) to pre-order \n" << "press (3) to Post-order\n" << "press (4) to in-order\n";
        cin >> op;
        if (op == 1){
            cout << "Enter element : ";
            cin >> data;
            insertNode(root,data);
        }
        else if (op == 2){
            preorder(root);
        }
        else if (op == 3)
        {
            postorder(root);
        }
        else if(op == 4){
            inorder(root);
        }
        else{
            cout << "Enter right choice!!";
        }
        cout << "\npress Y to continue or any key to exit!";
        cin >> ch;    
    }
    
    return 0;
}