#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch,a[50];
	int i=0;
	while(ch=getch())
	if((ch>=48&&ch<=57)||(ch>=40&&ch<=47)||ch==13||ch=='%')
	switch(ch)
	{
		case '1':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '2':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '3':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '4':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '5':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '6':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '7':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '8':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '9':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '0':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '.':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}	
		case '+':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '-':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '*':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '/':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '^':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '%':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case '(':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case ')':
			{
				a[i++]=ch;
				printf("%c",ch);
				break;
			}
		case 13:
			{
				a[i]='\0';
				printf("\n\n%s",a);
				exit(1);
			}																	
	}
	return 0;
}
