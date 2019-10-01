#include<stdlib.h>
#include<stdio.h>
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
NODE push(int item,NODE head)
{
   NODE p = getnode();
   p->data=item;
   p->next=head;
   head =p;
   return head;
}
NODE pop(NODE head)
{
   NODE  p = head;
   if(head == NULL)
   {
      printf("Stack is empty\n");
      return head;
   }
   head = p->next;
   printf("Deleted element is %d" , p->data);
   free(p);
   return head;
}
void display(NODE head)
{
   NODE p;
   if(head == NULL)
   {
      printf("Stack is empty\n");
      return;
   }
   printf("Stack Contents are: \n");
   p = head;
   while(p!=NULL)
   {
      printf("%d\n",p->data);
      p=p->next;
   }
   return;
}
int main()
{
   int c,item,pos;
   NODE head = (NODE)malloc(sizeof(struct node));
   printf("Enter value of first element:\n");
   scanf("%d",& item);
   head->data = item;
   c=1;
   while(c!=0)
   {
      printf("\nEnter 0 to EXIT\nENTER 1 TO PUSH\nENTER 2 TO POP\nENTER 3 TO DISPLAY\n");
      scanf("%d",&c);
   switch(c)
   {
      case 0:break;
      case 1: printf("Enter the item:\n");
              scanf("%d",&item);
              head = push(item,head);
              break;
      case 2: head = pop(head);
              break;
      case 3: display(head);
              break; 
      default: printf("Invalid Entry\n");
   }
   }
return 0;
}
