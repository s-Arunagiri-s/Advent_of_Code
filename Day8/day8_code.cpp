#include <bits/stdc++.h>
using namespace std;

unordered_map<string,pair<string,string>> lrMap;
string dir;
 
int
main ()
{
	
  fstream file;
  string tp;
  int init=0;
  string place;
  
  
  file.open ("day5.txt", ios::in);
  if (file.is_open ())
	{

	  while (getline (file, tp))
		{
		    if(init==0)
		    {
		        dir=tp;
		        init=1;
		    }
		    else if(tp[0]>='A' && tp[0]<='Z')
		    {
		       pair<string,string> dest;
		       
		       place= tp.substr(0,3);
		       dest.first= tp.substr(7,3);
		       dest.second=tp.substr(12,3);
		       lrMap[place]=dest;
		    }
		}
	
		int step=0;
		int i=0;
		string start="AAA";
		while(start!="ZZZ")
		{
		    cout<<start<<" ";
		    
		    if(dir[i]=='L')
		    {
		        start=lrMap[start].first;
		        i++;
		    }
		    else
		    {
		        start=lrMap[start].second;
		        i++;
		    }
		    
		    step++;
		    if(i==dir.size())
		    i=0;
		}
		cout<<step;
	}
	
	
}
