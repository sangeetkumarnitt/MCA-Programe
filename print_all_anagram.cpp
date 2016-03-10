#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string str[]={"cat", "dog", "tac", "god", "act"};
 
    int n=sizeof(str)/sizeof(str[0]);
    int i,j;
    vector<string> init(str,str+n);
    vector<string>::iterator s=init.begin();
    for(s=init.begin();s!=init.end();s++)
        sort((*s).begin(),(*s).end());
   for(s=init.begin();s!=init.end();s++)
      cout << *s << ' ';     
 
    map<string,vector<int> > hm;
    map<string,vector<int> > :: iterator it;
    for(i=0;i<n;i++)
    {
    	it = hm.find(init[i]);
    	if(it != hm.end())
    	{
    		(it->second).push_back(i);
		}
		else
		hm[init[i]].push_back(i);
    }
    cout<<"\n all anagrams together are:"<<endl;
 
    for(int i=0;i<n;++i)
    {
      it = hm.find(init[i]);
      if(it != hm.end())
      {
        vector<int> :: iterator v;
		for(v = (it->second).begin();v!=(it->second).end();++v)
        {
        	int k = *v;
        	cout<<" "<<str[k];
		}
	  }
	  hm.erase(init[i]);
}
 
return 0;
}
