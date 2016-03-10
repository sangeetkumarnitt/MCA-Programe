#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    char a[100000],b[100000];
    int c[200000],temp,j,i,k,index;
    
    
    cin >> t;
      while(t--)
        {
            temp=index=0;
            cin >> a;
            cin >> b;
            for(i=strlen(a)-1,j=strlen(b)-1;i>=0&&j>=0;i--,j--)
            {
                k=a[i]-'0'+b[j]-'0'+temp;
                temp=k/10;
                c[index++]=k%10;
            }
            while(i>=0)
            {
                k=a[i]-'0'+temp;
                temp=k/10;
                c[index++]=k%10;
                i--;
            }
            while(j>=0)
            {
                k=b[j]-'0'+temp;
                temp=k/10;
                c[index++]=k%10;
                j--;
            }
            c[index]=temp;
            bool t=false;
            for(i=index;i>=0;i--){
             if(c[index]==0)
             	 i--;  
				cout << c[i];
			
            }
            cout<<endl;
        }
        return 0;

}
