#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node* NODE;
NODE getnode(int item)
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}
NODE insert(NODE root, int item)
{
	if(root == NULL)
		return getnode(item);
	if(item<root->data)
		root->lchild=insert(root->lchild,item);
	else if(item>root->data)
		root->rchild=insert(root->rchild,item);
		
		return root;
}
void inorder(NODE root)
{
	if(root == 	NULL)
	{
		return;
	}
	inorder(root->lchild);
	printf("%d ",root->data);
	inorder(root->rchild);
}
void preorder(NODE root)
{
	if(root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(NODE root)
{
	if(root == NULL)
		return;
	preorder(root->lchild);
	preorder(root->rchild);
	printf("%d ", root->data);
}
int main()
{
	NODE root = NULL;
	int op,item;
	while(1)
	{
		printf("1 insert\n2 inorder\n3 preorder\n4 postorder\n5 exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("Enter element\n");
					scanf("%d",&item);
					root=insert(root,item);
					break;
			case 2: inorder(root);
					printf("\n");
					break;
			case 3: preorder(root);
					printf("\n");
					break;
			case 4: postorder(root);
					printf("\n");
					break;
			case 5:exit(0);
			default: printf("Invalid\n");
		}
	}
	return 1;
}
