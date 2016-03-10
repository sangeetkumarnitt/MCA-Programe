#include<stdlib.h>
void main(){
	int *i=(int*)malloc(20); 
	*i=100;
	free(i);
	printf("\nmain function: %d",*i);
	free(i);
   printf("\nmain function: %d",*i);
}

