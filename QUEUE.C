#include<stdio.h>
#define size 10
void insert(int item,int *r,int q[])
{
   if(*r ==size-1)
   {
      printf("Queue overflow\n");
      return;
   }
   *r = *r + 1;
   q[*r] = item;
}
int delete(int q[],int *f,int *r)
{
   int item;
   if(*f > *r)
   {
      printf("Queue underflow\n");
      return -9999;
   }
      item = q[*f];
      *f += 1;
      return item;
}
void display(int q[], int f, int r)
{
   int i;
   if(f>r)
   {
      printf("Queue underflow\n");
      return;
   }
   printf("Contents of queue are: \n");
   for(i = f;i<=r;i++)
   {
      printf("%d \n",q[i]);
   }
}
int main()
{
   int q[size],j,r,f,i,n,k=1;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   printf("\nEnter the elements of the queue\n");
   for(i = 0;i<n;i++)
   {
     scanf("%d",&q[i]);
   }
   f = 0;
   r = n-1;
   while(k!=0)
   {
     printf("\nEnter 0 to exit \nEnter 1 to insert \nEnter 2 to delete \nEnter 3 to display\n");
     scanf("%d",&k);
     switch(k)
     {
       case 0: printf("Thank you\n");
	       break;
       case 1: printf("Enter the number to be inserted \n");
	       scanf("%d",&j);
	       insert(j,&r,q);
	       break;
       case 2: j = delete(q,&f,&r);
	       if(j == -9999)
	       break;
	       printf("Deleted element is %d",j);
	       break;
       case 3: display(q,f,r);
	       break;
       default:printf("Invalid option\n");
     }
   }
   return 1;
}
