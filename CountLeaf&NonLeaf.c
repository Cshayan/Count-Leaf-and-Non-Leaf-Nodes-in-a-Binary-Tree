#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

int countLeaf(struct node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return countLeaf(root->left)+countLeaf(root->right);
}
int countNonLeaf(struct node *root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL) )
        return 0;
    else
        return 1+countNonLeaf(root->left)+countNonLeaf(root->right);
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Leaf count of the tree is %d", countLeaf(root));

   struct node* root1  = newNode(1);
    root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);
  printf("\nInternal/Non-Leaf count of the tree is %d", countNonLeaf(root1));

  return 0;
}

