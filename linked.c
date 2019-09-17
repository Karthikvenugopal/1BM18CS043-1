#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
typedef struct node* NODE;
NODE getnode()
{
   NODE p = (NODE)malloc(sizeof(struct node));
   if(p!=NULL)
   return p;
   printf("Memory not allocated\n");
   exit(0);
}
void insert_end(int item,NODE head)
{
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
}
NODE insert_front(int item, NODE head)
{
   NODE p = getnode();
   p->data=item;
   head = p;
   return head;
}
void insert(int item, NODE head, int pos)
{
   NODE curr,prev=NULL,q,p;
   int count = 1;
   p = getnode();
   p->data = item;
   p->next = NULL;
   if(head == NULL)
   {
     if(pos = 1)
     return;
     else
     printf("Invalid");
     }
     if(pos == 1)
     {
       p ->next = head;
       head = p;
     }
     else
     {
       curr = head;
       while(curr!=NULL && count !=pos)
       {
         prev = curr;
         curr = curr->next;
         count++;
       }
       if( count == pos)
       {
         prev->next = p;
         p->next=curr;
       }
       else
       printf("Invalid position");
       }
}
void display(NODE head)
{
  NODE p = head;
  if(head == NULL){
  printf("List empty\n");return;
  }
  printf("LInked list contents are:\n");
  while(p!= NULL)
  {
     printf("%d\n",p->data);
     p->next;
  }
}
int main()
{
   int choice,k,pos;
   NODE head = (NODE)malloc(sizeof(struct node));
   printf("Enter value of first element\n");
   scanf("%d",&k);
   head->data = k;
   choice = 1;
   while(choice !=0)
   {
      printf("Enter the choice\n");
      scanf("%d",&choice);
      switch(choice)
      {
      case 0: break;
      case 1: printf("Enter the element\n");
              scanf("%d",&k);
              insert_front(k,head);
              break;
      case 2: printf("Enter the element\n");
              scanf("%d",&k);
              insert_end(k,head);
              break;
      case 3: printf("Enter the element and position\n");
              scanf("%d%d",&k,&pos);
              insert_front(k,head);
              break;
      case 4: display(head);
              break;
      default:printf("Invalid choice");
      }
}        
}
