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
NODE enqueue(NODE head,int item)
{
   if(head == NULL)
   {
      NODE p = getnode();
      p->data = item;
      p->next = NULL;
      return p;
   }
   NODE p,q;
   q = getnode();
   q->data = item;
   p = head;
   while(p->next!=NULL)
   {
      p = p->next;
   }
   p->next = q;
   q->next = NULL;
   return head;
}
NODE dequeue(NODE head)
{
   NODE  p = head;
   if(head == NULL)
   {
      printf("Queue is empty\n");
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
      printf("Queue is empty\n");
      return;
   }
   printf("Queue Contents are: \n");
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
      printf("\nEnter 0 to EXIT\nENTER 1 TO ENQUEUE\nENTER 2 TO DEQUEUE\nENTER 3 TO DISPLAY\n");
      scanf("%d",&c);
   switch(c)
   {
      case 0:break;
      case 1: printf("Enter the item:\n");
              scanf("%d",&item);
              head = enqueue(head,item);
              break;
      case 2: head = dequeue(head);
              break;
      case 3: display(head);
              break; 
      default: printf("Invalid Entry\n");
   }
   }
return 0;
}

