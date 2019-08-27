#include<stdio.h>
int fact(int n)
{
if(n==1)
return 1;
return (n*fact(n-1));
}
void main()
{
int n,a;
printf("Enter a number:");
scanf("%d",&n);
a = fact(n);
printf("%d! = %d",n,a);
}
