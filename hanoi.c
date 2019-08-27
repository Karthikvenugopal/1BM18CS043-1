#include<stdio.h>
void tower(int n,char src,char dest,char temp)
{
  if(n==1)
  {
    printf("Move disk 1 from %c to %c \n",src,dest);
    return;
  }
  tower(n-1,src,temp,dest);
  printf("Move disk %d from %c to %c \n",n,src,dest);
  tower(n-1,temp,dest,src);
 }
 int main()
 {
   int n;
   printf("Enter the number of discs in the tower \n");
   scanf("%d",&n);
   tower(n,'A','C','B');
   return 1;
 }
    
