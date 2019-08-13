y#include<conio.h>
#include<stdio.h>
//Karthik Venugopal
//1BM18CS043
//push, pop, and display functions without global variable
//13th August 2019
int pop(int s[100], int *top);
void push(int s[100], int a, int *top);
void display(int s[100], int *top);
int main()
{
 int s[100],i,top=-1,n,k=1,a,e;
 clrscr();
 printf("Enter the number of stack elements\n");
 scanf("%d",&n);
 top = top + n;
 printf("Enter the stack elements\n");
 for(i=0;i<=top;i++)
 scanf("%d",&s[i]);

 while(k>=1)
{
 printf("Enter 0 to exit \n");
 printf("Enter 1 to push \n");
 printf("Enter 2 to pop \n");
 printf("Enter 3 to display \n");
 scanf("%d", &k);
 switch(k)
{
case 0:break;
case 1: printf("Enter the number to be pushed\n");
	scanf("%d",&a);push(s,a,&top);continue;
case 2: e = pop(s,&top);
	if(e !=-9999)
	printf("Popped element = %d\n",e);
	continue;
case 3: display(s,&top);
	continue;
default: continue;
}
}
getch();return 1;
}

int pop(int s[100], int *top)
{
 if(*top == -1)
  {
    printf("Stack is empty(underflow) \n");
    return -9999;
  }
else
return s[(*top)--];
}
void push(int s[100],int a,int *top)
{
 if(*top ==99)
{
 printf("Stack is full(Overflow)\n");
}
else
s[++(*top)]=a;
}
void display(int s[100],int *top)
{
int i;
if(*top==-1)
printf("Stack is empty (Underflow)\n");
else
{
printf("Stack elements are \n");
for(i=*top;i>=0;i--)
printf("%d\n",s[i]);
}
}