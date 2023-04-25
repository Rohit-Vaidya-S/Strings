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

int tree_height(struct node *root) {
    if (!root)

        return 0;
    else {
        int left_height = tree_height(root->left_child);
        int right_height = tree_height(root->right_child);
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
    int left_height = tree_height(tree->left_child);
    int right_height = tree_height(tree->right_child);
    int left_diameter = diameter(tree->left_child);
    int right_diameter = diameter(tree->right_child);
    int max_diameter = (left_diameter >= right_diameter) ? left_diameter : right_diameter;
 
    return ((left_height + right_height + 1) >= max_diameter) ? (left_height + right_height + 1) : max_diameter;
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
