#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 struct stack
{
	char op;
	struct stack *next1;
}*top1=NULL;
  struct postfix
 {
 	char opd;
 	struct postfix *next;
 }*top=NULL;
 typedef struct stack stack;
 typedef struct postfix pos;
 void push(char data)
 {
 	
 	pos *temp;
 	temp=(pos *)malloc(sizeof(pos));
 	if(temp==NULL)
 	{
 		printf("stack overflow");
 		exit(1);
 	}
 	temp->opd=data;
 	temp->next=top;
 	top=temp;
 }
 char pop()
 {
 	pos *temp; char item;
 	temp=top;
 	item=temp->opd;
 	top=top->next;
 	free(temp);
 	return item;
 }
  void push1( char data)
 {
 	
 	stack *temp;
 	temp=(stack *)malloc(sizeof(stack));
 	if(temp==NULL)
 	{
 		printf("stack overflow");
 		exit(1);
 	}
 	temp->op=data;
  	temp->next1=top1;
 	top1=temp;
 }
 char pop1()
 {
 	stack *temp; char item;
 	temp=top1;
 	item=temp->op;
  	top1=top1->next1;
 	free(temp);
 	return item;
 }

int match(char a,char b)
 {
 	if(a=='['&& b==']')
 	return 1;
 	if(a=='('&& b==')')
 	return 1;
 	if(a=='{'&& b=='}')
 	return 1;
 	else 
	 return 0;
 }
 int check1( char a[])
 {
 	/*stack *top1=NULL;*/
 	int i=0;char k,item;
 	while(a[i]!='\0')
 	{
 		 k=a[i++];
 		if(k=='('||k=='{'||k=='[')
 			push1(k);
 		if(k==')'||k=='}'||k==']')
 		{
 			if(top1==NULL)
 			{
				printf("braket of type'%c' is missing\n",k); 			
 				return 0;
 			}
 			else
 			{
 			
 			item=pop1();
			if(match(item,k))
		 	continue;
		 	else
			printf("braket of type'%c','%c' is missmatch\n",item,k);
			}
		}
 	}
 	if(top1==NULL)
 	{
		printf("no prenthises error\n\n");
		return 1;
	}
 	else
 	{

 		while(top1!=NULL)
 		{
 						
 			printf("braket of type '%c' is missing\n",top1->op);
 			top1=top1->next1;
 			
 		}
 	}
	
 }
  int check2(char a[])
 {
 	stack *p;
 	int i=0,flag=0;char k,item;
 	while(a[i]!='\0')
 	{
 		 k=a[i++];
 			push1(k);
	}
	
	p=top1;
	while(p!=NULL)
	{
		if(p->op>=42 && p->op<=47)
		{
			if(p->next1->op>=42 && p->next1->op<=47)
			{
				printf("operator '%c''%c' use together\n",p->next1->op,p->op);
				flag=1;
			}
		}
		p=p->next1;
	}
	if(flag==0)
	printf("no operator error:\n");
	while(top1!=NULL)
 		top1=top1->next1;
 	
}
int pri(char a)
{
	switch(a)
	{
		case '(':
			return 0;
		case '-':
		case '+':
			return 1;
		case '/':
		case '*':
		case '%':
			return 2;
		case '^':
			return 3;
		default:
			return 0;			
	}
}
void intopos( char a[])
 {
 	int i;char k,item;
 	for(i=0;i<strlen(a);i++)
 	{
 		k=a[i];
 		switch(k)
 		{
 			case '[':
 			{
 				push1(k);
 				break;
 			}
 			case ']':
 			{
 				while((item=pop1())!='[')
 						push(item);
 						break;
 			}
 			case '{':
 			{
 				push1(k);
 				break;
 			}
 			case '}':
 			{
 				while((item=pop1())!='{')
 						push(item);
 						break;
 			}
 			case '(':
 			{
 				push1(k);
 				break;
 			}
 			case ')':
 			{
 				while((item=pop1())!='(')
 						push(item);
 						break;
 			}
 			case '-':
 			case '+':
			case '/':
			case '*':
			case '^':
			case '%':
				{
					while((top1!=NULL)&&( pri(top1->op)>=pri(k)))
					{
						item=pop1();
						push(item);
					}
					push1(k);
					break;
				}
			default:
				push(k);	
				
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
  	int temp,k;
  	/*top=NULL;*/
  	
  	char b,c;
  	stack *p=top1;
  	while(p!=NULL)
  	{
  		
  		if(p->op>=48&&p->op<=57)
  		{
  			k=p->op-48;
  			push(k);
  		}
  		else
  		{
  			b=pop();
  			c=pop();
  			switch(p->op)
  			{
  				case '-':
  					{
  						temp=c-b;
  						break;
  					}
  				case '+':
  					{
  						temp=b+c;
  						break;
  					}
				case '*':
  					{
  						temp=b*c;
  						break;
  					}
				case '/':
  					{
  						temp=c/b;
  						break;
  					}
				case '%':
  					{
  						temp=c%b;
  						break;
  					}
				case '^':
  					{
  						temp=pow(c,b);
  						break;
  					}	  	  	  	  	
  			}
  			push(temp);
  		}
  		p=p->next1;
  	}
  }

int main()
{
	char infix[50];
	int a;
	gets(infix);

		
		
		while(1)
	{
		printf("Enter the choice");
		fflush(stdin);
		scanf("%d",&a);
		switch(a)
		{
			case 1:{
						printf("parentheses errors\n");
							check1(infix);
							printf("oprators error\n");
							check2(infix);
									break;
					}
			case 2:
			{
				intopos(infix);
				printf("postfif:-\n");
				stack *p;
				p=top1;
				while(p!=NULL)
				{
					printf("%c",p->op);
					p=p->next1;
				}
				printf("\n");			
				break;
			}
			case 3:
			{
				sol();
				printf("\nyour answer:=");
				printf("%d\n",top->opd);
				break;
			}		
		}
		
	}
	return 0;
}

