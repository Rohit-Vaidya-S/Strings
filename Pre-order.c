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

void preorder(struct node* passnode)
{
    if (passnode == NULL)

        return;
    printf("%d ", passnode->data);
    preorder(passnode->left_child);
    preorder(passnode->right_child);
}

int main(){
    root = insert(root,10);
    insert(root,6);
    insert(root,5);
    insert(root,15);
    inorder(root);
    printf("\n");
    
    return 0;
}
