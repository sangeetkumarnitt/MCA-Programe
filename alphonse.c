#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node *sort(struct node *start,float n,int pos);
 struct phon 
{
	char pho[10];
	struct phon *next2;
}*start2,*temp2,*p2;

  struct dep
{
	char de[20],re[20];
	int age1;
	struct dep *next1;
}*start1,*temp1,*p1;

 struct node
{
	char name[20],pos[20];
	int age;
	float sal;
	struct dep *d;
	struct phon *ph;
	struct node *next;
}*start,*temp,*p;
struct phon *pun(struct phon *start2)
{
	typedef struct phon phon;
	start2=NULL;
	int key=1;
	if(start2==NULL)
	{
		temp2=(phon*)malloc(sizeof(phon));
		printf("ENTER PHON NO.\n");
		scanf("%s",temp2->pho);
		temp2->next2=start2;
		start2=temp2;
	}
	printf("to continue press 1");
	scanf("%d",&key);
	if(key==1)
	{
	
	 while(key==1)
 {

	p2=start2;
	while(p2->next2!=NULL)
	p2=p2->next2;
		temp2=(phon*)malloc(sizeof(phon));
		printf("ENTER PHON NO.\n");
		scanf("%s",temp2->pho);	
		temp2->next2=NULL;
		p2->next2=temp2;
		printf("to continue press 1");
		scanf("%d",&key);

 }
}
else
return start2;
return start2;
}

struct dep *fun(struct dep *start1)
{
	typedef struct dep dep;
	int key=1;
	 start1=NULL;
	if(start1==NULL)
	{
		temp1=(dep*)malloc(sizeof(dep));
		printf("ENTER DEPENDENT NAME,RELATION,AGE");
		scanf("%s%s%d",temp1->de,temp1->re,&temp1->age1);
		temp1->next1=start1;
		start1=temp1;
	}
	printf("to continue press 1");
	scanf("%d",&key); 
	if(key==1)
	{
	
		 while(key==1)
			 {
			
				p1=start1;
				while(p1->next1!=NULL)
				p1=p1->next1;
				temp1=(dep*)malloc(sizeof(dep));
				printf("ENTER DEPENDENT NAME,RELATION,AGE");
				scanf("%s%s%d",temp1->de,temp1->re,&temp1->age1);
				temp1->next1=NULL;
				p1->next1=temp1;
				printf("to continue press 1");
				scanf("%d",&key);
			
			 }
	}
else
return start1;
return start1;
}
void display(struct node *start)
{
	struct node *q;
	q=start;
	while(q!=NULL)
	{
		printf("\nEmplyee informations\n");
		printf("NAME\tPOSITION\tAGE\tSALARY\n");
		printf("%s\t%s\t\t%d\t%.2f\n",q->name,q->pos,q->age,q->sal);
		printf("Emplyee dependent informations\n");
		printf("RELATION\tNAME\tAGE\n");
		while(q->d!=NULL)
		{
			printf("%s\t\t%s\t%d\n",q->d->de,q->d->re,q->d->age1);
			q->d=q->d->next1;
		}
		printf("PHON NO.S\n");
		while(q->ph!=NULL)
		{
				printf("%s\n",q->ph->pho);
				q->ph=q->ph->next2;
		}
	
		q=q->next;	

	}
}
struct node *kaushal(struct node *start)
{	
	typedef struct node node;
	int key=1,count=0;node *p;
	float n;
	if(start==NULL)
	{
		/*d=(struct dep*)malloc(sizeof(struct dep));//node *temp;*/
		temp=(node*)malloc(sizeof(node));
		printf("ENTER NAME, POSITION,AGE,SALARY\n");
		scanf("%s%s%d%f",temp->name,temp->pos,&temp->age,&temp->sal);	
		temp->d=fun(start1);
		temp->ph=pun(start2);
		temp->next=NULL;
		start=temp;
	}
	/*p=start;*/
	printf("to continue press 1");
	scanf("%d",&key);
	if(key==1)
	{
		while(key==1)
		{
			
				p=start;
				printf("Enter salary");
				scanf("%f",&n);
				while(p->next!=NULL)
				{
					
					if(p->sal>n)
					{
						count++;
						start=sort(start,n,count);
						count=0;
						break;
					}
					count++;
					p=p->next;
				}
					
					
						if(p->next=NULL)
						{
											
						temp=(node*)malloc(sizeof(node));
						printf("ENTER NAME, POSITION,AGE\n");
						scanf("%s%s%d",temp->name,temp->pos,&temp->age);
						temp->d=fun(start1);
						temp->ph=pun(start2);
						temp->sal=n;
						temp->next=NULL;
						p->next=temp;
						}
			
				printf("to continue press 1");
				scanf("%d",&key);
			
		}
	}
	else
	return start;
	return start;
}
struct node *sort(struct node *start,float n,int pos)
{
	typedef struct node node;
	node *temp,*p;int i;
	p=start;
	for(i=1;i<pos-1&&p!=NULL;i++)
	p=p->next;
	temp=(node*)malloc(sizeof(node));
	printf("ENTER NAME, POSITION,AGE\n");
	scanf("%s%s%d",temp->name,temp->pos,&temp->age);
	temp->d=fun(start1);
	temp->ph=pun(start2);
	temp->sal=n;
	if(pos==1)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		temp->next=p->next;
		p->next=temp;
	}
	return start;
}

int main()
{
	struct node *start=NULL;
	int k;
	while(1)
	{
		fflush(stdin);
		printf("Enter your choice");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
				{
					start=kaushal(start);
					break;
				}
			case 2:
				{
					display(start);
					break;
				}
			case 3:
				{
					display(start);
					break;
				}		
		}
	}	
	return 0;
}
