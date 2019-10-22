#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("Memory could not be allocated\n");
exit(0);
}
}
NODE insertend(NODE head,int item)
{
NODE p,q;
q = getnode();
q->data = item;
p = head;
if(head == NULL)
{
	head = q;
	return head;
}
while(p->next!=NULL)
{
p = p->next;
}
p->next = q;
q->next = NULL;
return head;
}
NODE delete_front(NODE head)
{
   NODE  p = head;
   if(head == NULL)
   {
      printf("List is empty\n");
      return head;
   }
   head = p->next;
   printf("Deleted element is %d\n" , p->data);
   free(p);
   return head;
}
void display(NODE head)
{
NODE p;
if(head == NULL)
{
printf("List is Empty\n");
return;
}
printf("Linked List Contents are: \n");
p = head;
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
return;
}
NODE sort(NODE head)
{
	NODE p;
	int swapped,t;
	do
	{
		swapped = 0;
		p = head;
		while(p->next!=NULL)
		{
			if(p->data > p->next->data)
			{	
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
				swapped = 1;
			}
			p = p->next;
		}
	}while(swapped);
	return head;
}
NODE rev(NODE head)
{
	NODE prev = NULL;
	NODE curr = head;
	NODE next = NULL;
	while (curr != NULL) 
	{
		next = curr->next;
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
    head = prev;
	return head;
}
NODE conc(NODE p, NODE q)
{
	NODE tmp;
	if(p == NULL)
		return q;
	else if(p == NULL)
		return q;
	else
	tmp = p;
	while(tmp->next!=NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = q;
	return p;
}
void main()
{
	NODE head = NULL, h2,p;
	int k = 1;
	int n;
	int item,i;
	while(k!=0)
	{
		printf("Enter 0 to exit\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to reverse\nEnter 5 to sort\n");
		scanf("%d", &k);
		switch(k)
		{
			case 0: break;
			case 1: printf("Enter the element to be inserted\n");
					scanf("%d",&item);
					head = insertend(head,item);
					break;
			case 2: head = delete_front(head);
					break;
			case 3: display(head);
					break;
			case 4: head = rev(head);
					break;
			case 5: head = sort(head);
					break;
			case 6: h2 = NULL;
					printf("Enter the number of elements in the second linked list\n");
					NODE p = getnode();
					scanf("%d",&item);
					p->data = item;
					p->next = p;
					h2 = p;
					scanf("%d",&n);
					printf("Enter the elements of the second node\n");
					for(i = 0; i<n ;i++)
					{
						p = getnode();
						scanf("%d",&item);
						p->data = item;
						p = p->next;
					}
					
					head = conc(head,h2);
					break;	
			default:printf("Invalid entry\n");
		}	
	}
}	
		
	
	
 
