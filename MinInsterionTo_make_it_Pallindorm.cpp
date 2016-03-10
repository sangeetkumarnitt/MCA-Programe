#include<iostream>
#include<cstring>
using namespace std;
int FindMinInsertion(char str[],int l,int h){
	if(l>h) return INT_MAX;
	if(l==h) return 0;
	if(l==h-1) return (str[l]==str[h]?0:1);
	return (str[l]==str[h])?FindMinInsertion(str,l+1,h-1):(min(FindMinInsertion(str,l,h-1),FindMinInsertion(str,l+1,h))+1);
}
int FindMinInsertion1(char str[],int n){
	int l,gap,h;
	int DP[n][n];
	memset(DP,0,sizeof(DP));
	for(gap=1;gap<n;gap++){
		for(l=0,h=gap;h<n;l++,h++){
			DP[l][h]=(str[l]==str[h])?DP[l+1][h-1]:(min(DP[l][h-1],DP[l+1][h])+1);
		}
	}
	return DP[0][n-1];
}

int main(){
	char str[50];
	cin >> str;
	cout <<FindMinInsertion(str,0,strlen(str)-1) << endl;
	cout <<	FindMinInsertion1(str,strlen(str));
	return 0;
}
