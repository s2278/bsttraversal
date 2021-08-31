/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
   
   int data; 
   struct node *leftChild;
   struct node *rightChild;
};
struct node *root = NULL;

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;
   if(root == NULL) {
      root = tempNode;
   } 
   else {
       current = root;
       parent = NULL;
       while(1){ 
           parent = current;
           if(data < parent->data){
               current = current->leftChild;
               if(current == NULL){
                   parent->leftChild = tempNode;
                   return;
                   
               }
               
           }
           else{
               current = current->rightChild;
               if(current == NULL){
                   parent->rightChild = tempNode;
                   return;
                   
               }
               
           }
           
       }            
       
   }
    
}
void preorder(struct node* root){
   if(root != NULL) {
      printf("%d ",root->data);
      preorder(root->leftChild);
      preorder(root->rightChild);
   }
}
void inorder(struct node* root) {
   if(root != NULL) {
      inorder(root->leftChild);
      printf("%d ",root->data);          
      inorder(root->rightChild);
   }
}

void postorder(struct node* root) {
   if(root != NULL) {
      postorder(root->leftChild);
      postorder(root->rightChild);
      printf("%d ", root->data);
   }
}
int main() {
   int n=7;
   int a[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(int i = 0; i < n; i++)
      insert(a[i]);

   printf("\nPreorder traversal: ");
   preorder(root);

   printf("\nInorder traversal: ");
   inorder(root);

   printf("\nPostorder traversal: ");
   postorder(root);       

   return 0;
}
