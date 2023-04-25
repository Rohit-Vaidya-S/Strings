#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    struct  node *left_child;
    int data;
    struct node *right_child;
}*root = NULL;

struct node *insert(struct node *passnode, int key){
    struct node *temp = NULL;
    if(passnode==NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = key;
        temp->left_child = temp->right_child = NULL;
        
        return temp;
    }
    if(key<passnode->data){
        passnode->left_child = insert(passnode->left_child, key);
    }
    else{
        passnode->right_child = insert(passnode->right_child, key);
    }

    return passnode;
}

void inorder(struct node *passnode){
    if(passnode){
        inorder(passnode->left_child);
        printf("%d ",passnode->data);
        inorder(passnode->right_child);
    }
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left_child != NULL)
        current = current->left_child;
 
    return current;
}
 
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
    
        return root;
    if (key < root->key)
        root->left_child = deleteNode(root->left_child, key);
    else if (key > root->key)
        root->right_child = deleteNode(root->right_child, key);
    else {
        // node with only one child or no child
        if (root->left_child == NULL) {
            struct node* temp = root->right_child;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left_child;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right_child);
        root->key = temp->key;
        root->right_child = deleteNode(root->right_child, temp->key);
    }
    
    return root;
}

int main(){
    root = insert(root,10);
    insert(root,6);
    insert(root,5);
    insert(root,15);
    inorder(root);
    printf("\nDelete 15\n");
    root = deleteNode(root, 15);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    
    return 0;
}
