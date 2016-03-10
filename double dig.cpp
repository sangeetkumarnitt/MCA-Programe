#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string.h>
 struct stack
{
	char op[3];
	struct stack *next1;
}*top1=NULL;
  struct postfix
 {
 	char opd[5];
 	struct postfix *next;
 }*top=NULL;
 typedef struct stack stack;
 typedef struct postfix pos;
   char *p ;
 void push( char b[])
 
 {
 	
 	pos *temp;
 	temp=(pos *)malloc(sizeof(pos));
 	if(temp==NULL)
 	{
 		printf("stack overflow");
 		exit(1);
 	}
 	strcpy(temp->opd,b);
 	temp->next=top;
 	top=temp;
 }
 char pop()
 {
 	pos *temp; char c[6];
 	temp=top;
 	strcpy(c,temp->opd);
 	p=(char*)malloc(strlen(c)+1);
 	strcpy(p,c);
 	top=top->next;
 	free(temp);
 	
 }
  void push1( char b[])
 {
 	
 	stack *temp;
 	temp=(stack *)malloc(sizeof(stack));
 	if(temp==NULL)
 	{
 		printf("stack overflow");
 		exit(1);
 	}
 	strcpy(temp->op,b);
  	temp->next1=top1;
 	top1=temp;
 }
 char pop1()
 {
 	stack *temp;char c[5];
 	temp=top1;
 	strcpy(c,temp->op);
 	p=(char*)malloc(strlen(c)+1);
 	strcpy(p,c);
  	top1=top1->next1;
 	free(temp);

	
 }

int pri(char a[])
{
		
		if(strcmp(a,"(")==0)
			return 0;
		if((strcmp(a,"-")==0)||(strcmp(a,"+")==0))
			return 1;
		if((strcmp(a,"/")==0)||(strcmp(a,"*")==0)||(strcmp(a,"%")==0))
			return 2;
		if((strcmp(a,"^")==0))
			return 3;
		else
			return 0;			
	
}
int fun(char a[])
	{
	
	 int i, sum=0,p=1,l;
	 l=strlen(a)-1;
	for(i=l;i>=0;i--)
	{
		a[i]-=48;
		sum+=p*a[i];
		p*=10;
		
	}
	return sum;
	//("%d  %d",sum,l);
}
char pun(int temp )
	{
	 char a[6];
	 int i=0, sum=0,l;
	while(temp>0)
	{
		l=temp%10;
		a[i++]=l+48;
		temp/=10;
	}
	a[i]='\0';
	strrev(a);
	p=(char*)malloc(strlen(a)+1);
	strcpy(p,a);
	}

void intopos( char a[])
 {
 	
 	int i,j=0,count=1;char b[10],item[5],ch;
 	while(a[i]!='\0')
 	{
 		if(a[i]>=97&&a[i]<=122)
 		{
 			printf("\nEnter the value of constant %d:-",count++);
 			while((ch=getche())!=13)
 			{
 				b[j]=ch;
 				j++;
 				
 			}
 			b[j]='\0';j=0,i++;
 			push(b);continue;
 			//printf("%s\n",b);
 		}
 		if(a[i]>=48&&a[i]<=57)
 		{
 			while(a[i]>=48&&a[i]<=57)
 			{
 				b[j]=a[i];
 				i++;j++;
 				
 			}
 			b[j]='\0';j=0;
 			push(b);continue;
 			//printf("%s\n",b);
 		}
 		else
 		{
 			b[j++]=a[i];
 			b[j]='\0';j=0;i++;
 			if(strcmp(b,"[")==0)
 				push1(b);
 			if(strcmp(b,"]")==0)	 			
 			
 			{
 				pop1();
 				while(strcmp(p,"[")!=0)
 				{
 					
 					push(p);
 					pop1();
 		
 				}continue;
 			}
 			if(strcmp(b,"{")==0)
 				push1(b);
 			if(strcmp(b,"}")==0)	 			
 			
 			{
 				pop1();
 				while(strcmp(p,"{")!=0)
 				{
 					
 					push(p);
 					pop1();
 		
 				}continue;
 			}
 			if(strcmp(b,"(")==0)
 				push1(b);
 			if(strcmp(b,")")==0)	 			
 			
 			{
 				pop1();
 				while(strcmp(p,"(")!=0)
 				{
 					
 					push(p);
 					pop1();
 		
 				}continue;
 			}
 			if((strcmp(b,"-")==0)||(strcmp(b,"+")==0)||(strcmp(b,"*")==0)||(strcmp(b,"/")==0)||(strcmp(b,"^")==0)||(strcmp(b,"%")==0))
 				{
					while((top1!=NULL)&&( pri(top1->op)>=pri(b)))
					{
						pop1();
						push(p);
					}
					push1(b);
				}
 			//printf("%s\n",b);
 			
 		}
 	}
 
 	
 					
 	while(top1!=NULL)
 	{
 		push(top1->op);
 		top1=top1->next1;
 	}
 	while(top!=NULL)
				{
					push1(top->opd);
					top=top->next;
				}		
}


void sol()
  {
  	int b,c,temp;
  	//top=NULL;
  	char k[6],s[6],t[10];
  	stack *q=top1;
  	while(q!=NULL)
  	{
  		strcpy(t,q->op);
  		if((strcmp(t,"-")==0)||(strcmp(t,"+")==0)||(strcmp(t,"*")==0)||(strcmp(t,"/")==0)||(strcmp(t,"^")==0)||(strcmp(t,"%")==0))
			{
  			pop();
  			b=fun(p);
  			pop();
  			c=fun(p);
  			
  				if((strcmp(t,"-")==0))
  					temp=c-b;
  				if((strcmp(t,"+")==0))
  					temp=c+b;
				if((strcmp(t,"*")==0))
  					temp=c*b;
				if((strcmp(t,"/")==0))
  					temp=c/b;
				if((strcmp(t,"%")==0))
  					temp=c%b;
				if((strcmp(t,"^")==0))
  					temp=pow(c,b);
					  	  	  	  	  	
  				pun(temp);	
  				push(p);	  	  	  	  	
  			}
  			else
  			push(t);
  		q=q->next1;
  	}
}
  
  


 int main()
 {
 	char a[50];
 	int gan;
 	gets(a);
 	intopos(a);
 	stack *p;
				p=top1;
				while(p!=NULL)
				{
					printf("%s",p->op);
					p=p->next1;
				}
				printf("\n");
	sol();
				printf("\nyour answer:=");
				gan=fun(top->opd);
				printf("%d\n",gan);						
				
 	return 0;
 }
 

