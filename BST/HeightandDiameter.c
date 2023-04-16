#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    struct  node *lchild;
    int data;
    struct node *rchild;
}*root = NULL;

struct node *insert(struct node *p, int key){
    struct node *t = NULL;
    if(p==NULL){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key<p->data){
        p->lchild = insert(p->lchild, key);
    }
    else{
        p->rchild = insert(p->rchild, key);
    }
  
    return p;
}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
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
