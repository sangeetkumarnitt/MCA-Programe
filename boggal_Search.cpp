#include<iostream>
using namespace std;
char boggale[][3]={
								{'G','I','Z'},
                      			{'U','E','K'},
                       			{'Q','S','E'}	
				  };
bool Boggal_Search(char a[],int r,int c,int i){
	if(r<3&&c<3){
		if(a[i]=='\0')
		{
			cout << r << c <<endl;
			return true;
		}
		if(a[i]==boggale[r][c]){
			return Boggal_Search(a,r-1,c-1,i+1)||Boggal_Search(a,r-1,c+1,i+1)|| Boggal_Search(a,r+1,c+1,i+1)||Boggal_Search(a,r+1,c-1,i+1)|| Boggal_Search(a,r-1,c,i+1)|| Boggal_Search(a,r,c+1,i+1)||Boggal_Search(a,r,c-1,i+1)|| Boggal_Search(a,r+1,c,i+1);
		}
	
	}
	else
	
	return false;
}
				  
				  
int  main(){
	int t;
	cin >> t;
	while(t--){
		char a[20];
		cin >> a;
		int i=0;
		for(int r=0;r<3;r++)
		{
			for(int c=0;c<3;c++)
			 {
			 	if(boggale[r][c]==a[0]){
					cout << r << " " << c <<endl;	
					Boggal_Search(a,r,c,0);
					break;
				}
				else
				{
					cout << "i m \n";
				}
				 
			 }
		}
		  
	}
	return 0;
}
