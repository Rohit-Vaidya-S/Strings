#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    struct  node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;

struct node *insert(struct node *passnode, int key){

    struct node *temp = NULL;
    if(passnode==NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = key;
        temp->lchild = temp->rchild = NULL;
        
        return temp;
    }
    if(key<passnode->data){
        passnode->lchild = insert(passnode->lchild, key);
    }
    else{
        passnode->rchild = insert(passnode->rchild, key);
    }
    return passnode;
}

void inorder(struct node *passnode){
    if(passnode){
        inorder(passnode->lchild);
        printf("%d ",passnode->data);
        inorder(passnode->rchild);
    }
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
