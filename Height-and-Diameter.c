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

int tree_height(struct node *root) {
    if (!root)

        return 0;
    else {
        
        int left_height = tree_height(root->lchild);
        int right_height = tree_height(root->rchild);
      
        if (left_height >= right_height)

            return left_height + 1;
        else

            return right_height + 1;
    }
}

int diameter(struct node *tree)
{
    if (tree == NULL)

        return 0;
 
    int lheight = tree_height(tree->lchild);
    int rheight = tree_height(tree->rchild);
    int ldiameter = diameter(tree->lchild);
    int rdiameter = diameter(tree->rchild);
 
    int max_diameter = (ldiameter >= rdiameter) ? ldiameter : rdiameter;
 
    return ((lheight + rheight + 1) >= max_diameter) ? (lheight + rheight + 1) : max_diameter;
}

int main(){
    root = insert(root,10);
    insert(root,6);
    insert(root,5);
    insert(root,15);
    inorder(root);
    printf("\n");
    int height = tree_height(root);
    printf("Height of the Binary Tree: %d\n", height);
    printf("Diameter of the given binary tree is %d\n",diameter(root));

    return 0;
}
