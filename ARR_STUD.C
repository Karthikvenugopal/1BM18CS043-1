#include<stdio.h>
#include<conio.h>
void main()
{
  struct student
  {
    int id, age, marks;
  }st[20];
  int i;
  clrscr();
  for(i=0;i<10;i++)
  {
    printf("Enter the details of the student(ID, age, marks) %d\n",i+1);
    scanf("%d%d%d",&st[i].id,&st[i].age,&st[i].marks);
    if(st[i].age>20 && st[i].marks>=0 && st[i].marks<=100)
    {
      printf("student details are valid\n");
      if(st[i].marks>=65)
      printf("student is eligible for admission\n");
      else
      printf("student is not eligible for admission\n");
    }
    else
    printf("students details are invalid\n");
    }
    getch();
  }

