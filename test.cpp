#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--){
        long long n,i;
        cin >> n;
            int count =1;
            bool flag=false;
            if(n&1)
            {
            	cout << '0'<<'\n';
			}
			else{
            	for(i=2;i<=sqrt(n);i+=1){
            	  if(n%i==0){
            		if(i%2==0){	
            			count++;
           		 	}		
            		if(((n/i)!=i)&&((n/i)%2==0)){
            			count++;
					}
				  } 
				}
				cout << count<<'\n';
			}
       }
    return 0;
}

