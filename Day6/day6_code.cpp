#include <bits/stdc++.h>
using namespace std;

int
main ()
{
  fstream file;
  vector <int> Time;
  vector<int> dist;
  vector<int> result;
  int i;
  string tp;
  string T;
  int len=0;
  file.open ("day5.txt", ios::in);
  if (file.is_open ())
	{

	  while (getline (file, tp))
		{
		  if(tp[0]=='T')
		  {
		  i=0;
          while(isdigit(tp[i])==0)
          {
              i++;
          }
          string ss = tp.substr (i, tp.size ()-i);
          
			  stringstream X (ss);
			  while (getline (X, T, ' '))
				{
				    
				    if(isdigit(T[0]))
				    {
				    Time.push_back (stoi (T));
				    len++;
				    }
				}
		  }
		  else if(tp[0]=='D')
		  {
		      i=0;
          while(isdigit(tp[i])==0)
          {
              i++;
          }
          string ss = tp.substr (i, tp.size ()-i);
          
			  stringstream X (ss);
			  while (getline (X, T, ' '))
				{
				    
				    if(isdigit(T[0]))
				    dist.push_back (stoi (T));
				}
		  }
		}
		int speed;
		int tim;
		int d;
		int wins=0;
		
		for(int i=0;i<len;i++)
		{
		    wins=0;
		    for(int j=0;j<Time[i];j++)
		    {
		        speed=j;
		        tim=Time[i]-j;
		        d=speed*tim;
		        if(d>dist[i])
		        {
		            wins++;
		        }
		    }
		    if(wins>0)
		    result.push_back(wins);
		}
	}	
	int ans=1;
	for(auto x: result)
	{
	    ans*=x;
	}
	cout<<ans;
	
	

}
