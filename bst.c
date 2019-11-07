 
/**
Copyright All Rights Reserved by Nirdesh Kumar
Project : Binary Search Tree
Authors: Nirdesh Kumar 
Purpose: Build and use BST for knowledge point of view
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* leftchild;
	struct node* rightchild;
}node;

typedef struct tree{
	node* root;
	int size;
}bst;
node* Find(node* root,int data);
node* FindMin(node* root);
node* FindMax(node* root);
node* DeleteNode(node* root,int data);

bst* createBst(){
	bst* t=(bst*)malloc(sizeof(bst));
	t->root=NULL;
	t->size=0;
	return t;
}
node* insertIntoBst(node* root,int data){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
	
	if(root==NULL){
		printf("memory error");
		return;
	}
	else{root->data=data;
	root->leftchild=root->rightchild=NULL;
	}
	}
	else{
		if(data<(root->data))
			root->leftchild=insertIntoBst(root->leftchild,data);
		else if(data>(root->data))
			root->rightchild=insertIntoBst(root->rightchild,data);
	}
	return root;
}
inorder(node* root){
	if(root){
		inorder(root->leftchild);
		printf("\t%d",root->data);
		inorder(root->rightchild);
	}
}
preOrder(node* root){
	if(root){
		printf("\t%d",root->data);
		preOrder(root->leftchild);
		preOrder(root->rightchild);
	}
}
postOrder(node* root){
	if(root){
		postOrder(root->leftchild);
		postOrder(root->rightchild);
		printf("\t%d",root->data);
	}
	
} 
node* DeleteNode(node* root,int data){
	
	if(root==NULL) return NULL;
	else if (data<(root->data))
		root->leftchild=DeleteNode(root->leftchild,data);
	else if(data>(root->data))
		root->rightchild=DeleteNode(root->rightchild,data);
	else {
		if(root->leftchild==NULL && root->rightchild==NULL){
			free(root);
			root=NULL;
	}
	else if(root->leftchild==NULL){
		node* temp=root;
		root=root->rightchild;
		free(temp);
	}
	else if(root->rightchild==NULL){
		node* temp=root;
		root=root->leftchild;
		free(temp);
		
	}
	else{
		node* temp=FindMin(root->rightchild);
		root->data=temp->data;
		root->rightchild=DeleteNode(root->rightchild,temp->data);
	}
	}
	return root;
}
node* Find(node* root,int data){
	if(root==NULL)
		return NULL;
	if(data<root->data)
		return Find(root->leftchild,data);
	else if(data>root->data)
		return Find(root->rightchild,data);
	return root;
}
node* FindMax(node* root){
	if(root==NULL) return NULL;
	else if(root->rightchild==NULL) return root;
	else return (FindMax(root->rightchild));
	
}
node* FindMin(node* root){
	if(root==NULL) return NULL;
	else if(root->leftchild==NULL) return root;
	else return (FindMin(root->leftchild));
}
int main(){
	bst *t=createBst();
	  t->root=(node*)malloc(sizeof(node));
	(t->root)->data=10;
	(t->root)->rightchild=NULL;
	(t->root)->leftchild=NULL;
	t->root=insertIntoBst(t->root,5);
		t->root=insertIntoBst(t->root,18);
		t->root=insertIntoBst(t->root,4);
		t->root=insertIntoBst(t->root,7);
		t->root=insertIntoBst(t->root,3);
		t->root=insertIntoBst(t->root,12);
		t->root=insertIntoBst(t->root,19);t->root=insertIntoBst(t->root,6);t->root=insertIntoBst(t->root,8);
		inorder(t->root);printf("\n");
		postOrder(t->root);
		printf("\n");
		preOrder(t->root);
		node* temp1=Find(t->root,7);
		node* temp2=FindMin(t->root);
		node* temp3=FindMax((t->root)->leftchild);
		printf("\n%d\nmin is  -> %d\nmax is-> %d",temp1->data,temp2->data,temp3->data);
		t->root=DeleteNode(t->root,19);inorder(t->root);
}
