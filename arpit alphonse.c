#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct mob
{
       char phone[234];
       struct mob *next1;       
};
struct employee
{
       char name[32];
       char empid[32];
       char desi[32];
       int age;
       float salary;
       struct employee *link_ph;
       struct employee *next;
       }*start=NULL;
create()
{
        int i;
        struct employee *temp,*temp1;
        struct mob *p=NULL;
        temp=(struct employee *)malloc(sizeof(struct employee));
        fflush(stdin);
        printf("Enter name for the employee\n");
        gets(temp->name);
        printf("Enter empid for the employee\n");
        gets(temp->empid);
        printf("Enter designation for the employee\n");
        gets(temp->desi);
        printf("Enter age\n");
        scanf("%d",&temp->age);
        printf("Enter his salary\n");
        scanf("%f",&temp->salary);
        fflush(stdin);
        printf("GOing to work for contact details\n");
        do
        {        
        struct mob *m,*m1;
        m=(struct mob *)malloc(sizeof(struct mob));
        printf("Enter phone no.\n");
        gets(m->phone);
        if(p==NULL)
        {
                   p=m;
                   temp->link_ph=p;
                   m->next1=NULL;
        }
        else
        {
             m1=p;
             while(m1->next1!=NULL)
             m1=m1->next1;
             m1->next1=m;
             m->next1=NULL;
        }
        printf("you want to enter 1 more mobile no. press 3 to exit else any key\n");
        scanf("%d",&i);
        fflush(stdin);
        }while(i!=3);
       
       if(start==NULL)
       {
              start=temp;
              temp->next=NULL;
       }
       else
       {
             temp1=start;
             while(temp1->next!=NULL)
             temp1=temp1->next;
             temp1->next=temp;
             temp->next=NULL;
       }
}              

display()
{
         struct employee *temp;
         temp=start;
         if(temp==NULL)
         printf("LIst is empty\n");
         else
         {
             while(temp!=NULL)
             {
                   printf("\n\nthe name%s",temp->name);
                   printf("\nthe empid%s",temp->empid);
                   printf("\nthe desi%s",temp->desi);
                   printf("\nthe age%d",temp->age);
                   printf("\nthe salary%f",temp->salary);
                   printf("\nhis contacts are as follows\n");
                   struct mob *m,*n;
                   m=temp->link_ph;
                   if(m==NULL)
                      printf("NO no.s are there\n");
                   else
                   {
                       while(m!=NULL)
                       {
                            printf("\nno. is\t%s",m->phone);
                            m=m->next1;
                       }
                   }
                   temp=temp->next;
             }
         }                              
}  


main()
{
      int i;
      do
      {
      printf("\n**********************|||*****************||********************");    
      printf("\nPress 1 for inserting employees data\n");
      printf("Press 2 for displaying\n");
      printf("Press 3 for exiting\n");
      scanf("%d",&i);
      switch(i)
      {
               case 1:create();
                      break;
               case 2:display();
                      break;
               default:exit(0);
      }
      }
      while(i!=3);                      
     getch();
}
