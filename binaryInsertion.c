#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *llink,*rlink;
};
struct node *getnode(){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("No enough memory\n");
		return NULL;
	}
	newnode->value=0;
	newnode->llink=NULL;
	newnode->rlink=NULL;
	return newnode;
}
int ele;
struct node* insert(struct node* root){
	struct node* nn=getnode();
	nn->value=ele;
	if(root==NULL){
		return nn;
	}
	if(root->value > ele)
		root->llink=insert(root->llink);
	else
		root->rlink=insert(root->rlink);
	return root;
}
void display(struct node* root){
	if(root==NULL)return;
	display(root->llink);
	printf("%d ",root->value);
	display(root->rlink);
	return;
}
struct node* delete(struct node *root){
	if(root==NULL){
		printf("Element dosent exit");
		return root;
	}
	if(ele==root->value){
		if((root->llink==NULL)&&(root->rlink==NULL)){
			free(root);
			return NULL;
		}
		if((root->llink==NULL)&&(root->rlink!=NULL)){
			return root->rlink;
		}
		if((root->llink!=NULL)&&(root->rlink==NULL)){
			return root->llink;
		}
		struct node *temp=root->rlink;
			while(temp->llink!=NULL)temp=temp->llink;
			temp->llink=root->llink;
		return root->rlink;
	}
	if(ele>root->value)
		root->rlink=delete(root->rlink);
	else if(ele<root->value)
		root->llink=delete(root->llink);
	return root;
}
void main(){
	int choice;
	struct node* root=NULL;
	for(;;){
		printf("1.Insert 10 elements\n2.Display\n3.deletion\n4.Exit\n Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter element to be inserted:");
					int i;
					for(i=0;i<10;i++){
						scanf("%d",&ele);
						root=insert(root);
					}
					break;
			case 2:display(root);break;
			case 3:if(root==NULL){
						printf("Trees is empty");
						break;
					}
					printf("Enter element to be deleted:");
					scanf("%d",&ele);
					root=delete(root);
					break;
			default: exit(0);
		}
	}
}
