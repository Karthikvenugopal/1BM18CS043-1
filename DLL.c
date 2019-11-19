#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
	
};
typedef struct node *NODE;
NODE getnode()
{
	NODE p = (NODE)malloc(sizeof(struct node));
	if(p==NULL)
	exit(0);
	return p;
}
NODE insert(NODE head,int val)
{
	
	NODE p = getnode();
	p->data = val;
	p->next = head;
	p->prev = NULL;
	if(head !=NULL){
	head->prev = p;}
	head = p;
	return head;
}
NODE linsert(NODE head,int val,int posv)
{
	if(head == NULL)
	{
		printf("List is empty. Cannot insert\n");
		return head;
	} 
	if(head->data == val)
	{
		head = insert(head,val);
		return head;
	}
	NODE p = head;
	NODE ele = getnode();
	ele->data = val;
	while(p!= NULL)
	{
		if(p->data == posv)
		{
			ele->next = p;
			ele->prev = p->prev;
			p->prev->next = ele;
			p->prev = ele;
			return head;
		}
		p=p->next;
	}
	printf("Not found\n");
	return head;
}
NODE del(NODE head, int val)
{
	NODE p = head;
	if(head == NULL)
	{
		printf("List is empty\n");
		return head;
	}
	if(head->data == val)
	{
		head = head->next;
		free(p);
		return head;
	}
	while(p!=NULL)
	{
		if(p->data == val)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
			return head;
		}
		p=p->next;
	}
	printf("Not found\n");
	return head;
}
void display(NODE head)
{
	NODE p = head;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("The elements of the list are\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
void main()
{
	NODE head = NULL;
	int k = 1,val,posv;
	while(k!=0)
	{
		printf("0 exit\n1 insert front\n2 insert left\n3 delete\n4 display\n");
		scanf("%d",&k);
		switch(k)
		{
			case 0: break;
			case 1: printf("Enter the element\n");
					scanf("%d",&val);
					head = insert(head,val);
					break;
			case 2: printf("Enter the element to be inserted and the element left of which it has to be inserted\n");
					scanf("%d%d",&val,&posv);
					head = linsert(head,val,posv);
					break;
			case 3: printf("Enter the element");
					scanf("%d",&val);
					head = del(head, val);
					break;
			case 4: display(head);
					break;
			default:printf("Invalid\n");
		}
	}
}
		
	
		
	
