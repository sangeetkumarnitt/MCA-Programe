#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    char a[500000],b[500000],
    int c[5000],temp,j,i,k,index;
    cin >> t;
      while(t--)
        {
            temp=index=0;
            cin >> a;
            cin >> b;
            for(i=strlen(a)-1,j=strlen(b)-1;i>=0&&j>=0;i--,j--)
            {
                k=a[i]-'0'+b[j]-'0'+temp;
                k=j/10;
                c[index++]=k%10;
            }
            for(i=index-1;i>=0;i--)
                cout << c[i];
        }
        return 0;

}
