#include<iostream>
using namespace std;
int date[]={0,3,3,6,
			1,4,6,
			2,5,0,
			3,5,1
			};
			
int main(){
	int dd,mm,y;
	cin >> dd >>mm >> y;
	int res =0;
	if(mm>2&&((y%4==0&&y%100!=0)||y%400==0))
		res++;
	y--;	
	y=y%400;
	res=(res+y/4*2+(y-y/4)+dd+date[mm-1])%7;
	cout << res <<'\n';
	return 0;
}
