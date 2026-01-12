//AVL TREE
#include <stdio.h>
#include<stdlib.h>

struct AvlNode{
	int data;
	struct AvlNode* left;
	struct AvlNode* right;
	int height;
};

int height(struct AvlNode* root){
	if(root==NULL){
		return 0;
	}
	else{
		return root->height;
	}
}

int max(int a, int b){
	return (a>b)?a:b;
}

struct AvlNode* leftRotate(struct AvlNode* y){
	struct AvlNode* x = y->right;
	struct AvlNode* T2 = x->left;
	x->left = y;
	y->right = T2;
	y->height = max(height(y->left),height(y->right))+1;
	x->height = max(height(x->left),height(x->right))+1;
	return x;
} 

struct AvlNode* rightRotate(struct AvlNode* y){
	struct AvlNode* x = y->left;
	struct AvlNode* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left),height(y->right))+1;
	x->height = max(height(x->left),height(x->right))+1;
	return x;
} 

int balancing(struct AvlNode* root){
	if(root==NULL){
		return 0;
	}
	else{
		return (height(root->left)-height(root->right));
	}
}

struct AvlNode* insert(struct AvlNode* root,int data){
	if(root==NULL){
		struct AvlNode* root = (struct AvlNode*)malloc(sizeof(struct AvlNode));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		root->height = 1;
		return root;
	}
	if(data<root->data){
		root->left = insert(root->left,data);
	}
	else if(data>root->data){
		root->right = insert(root->right,data);
	}
	root->height = max(height(root->left),height(root->right))+1;
	
	int bf = balancing(root);
	if(bf>1 && data < root->left->data){
		return rightRotate(root);
	}
	if(bf<-1 && data>root->right->data){
		return leftRotate(root);
	}
	if(bf>1 && data > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(bf<-1 && data < root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

struct AvlNode* maxchild(struct AvlNode* root){
	if(root == NULL || root->right ==NULL){
		return root;
	}
	else{
		return (maxchild(root->right));
	}
}

struct AvlNode* deleteA(struct AvlNode* root,int data){
	if(root==NULL){
		return NULL;
	}
	struct AvlNode* temp;
	if(data <root->data){
		root->left = deleteA(root->left,data); 
	}
	else if(data>root->data){
		root->right = deleteA(root->right,data);
	}
	else{
		// Element found
		if(root->right && root->left){
			temp = maxchild(root->left);
			root->data = temp->data;
			root->left = deleteA(root->left,temp->data);
		}
		else {
    // Node with zero or one child
   		 temp = root;
   		 if (root->left == NULL) {
       		 root = root->right;
 	   }
  		  else if (root->right == NULL) {
    	    root = root->left;
    	}
    	free(temp);
		}
	}
	
	if (root == NULL)
		return NULL;
	
	root->height = max(height(root->left),height(root->right))+1;
	
	int bf = balancing(root);
	
	if(bf>1 && balancing(root->left)>=0){//no right child (heavy left)
		return rightRotate(root);
		}
	if(bf<-1 && balancing(root->right)<0){//only right (heavy right)
		return leftRotate(root);
		}
	if(bf>1 && balancing(root->left)<0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
		}
	if(bf<-1 && balancing(root->right)>=0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}	
	return root;
}

void display(struct AvlNode* root){
	if(root==NULL){
		return;
	}
	else{
		display(root->left);
		printf("%d\t",root->data);
		display(root->right);
	}
}

int main(){
	struct AvlNode* root = NULL;
	root=insert(root,157);
	root=insert(root,110);
	root=insert(root,147);
	root=insert(root,122);
	root=insert(root,111);
	root=insert(root,149);
	root=insert(root,151);
	root=insert(root,141);
	root=insert(root,123);
	root=insert(root,112);
	root=insert(root,117);
	root=insert(root,133);
	display(root);
}
