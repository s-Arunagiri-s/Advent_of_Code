#include <bits/stdc++.h>
using namespace std;

unordered_map < string, pair < string, string >> lrMap;
string dir;

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

int
main ()
{

  fstream file;
  string tp;
  int init = 0;
  string place;
  vector < string > starts;
  vector < int >steps;
  file.open ("day5.txt", ios::in);
  if (file.is_open ())
	{

	  while (getline (file, tp))
		{
		  if (init == 0)
			{
			  dir = tp;
			  init = 1;
			}
		  else if (tp[0] >= 'A' && tp[0] <= 'Z')
			{
			  pair < string, string > dest;

			  place = tp.substr (0, 3);
			  dest.first = tp.substr (7, 3);
			  dest.second = tp.substr (12, 3);
			  lrMap[place] = dest;
			  if (place[2] == 'A')
				starts.push_back (place);
			}
		}
	  string start;
	  int step = 0;
	  int i = 0;
	  for (int j = 0; j < starts.size (); j++)
		{

		  start = starts[j];
		  int step = 0;
		  int i = 0;
		  while (start[2] != 'Z')
			{
			  //cout << start << " ";
			  if (dir[i] == 'L')
				{
				  start = lrMap[start].first;
				  i++;
				}
			  else
				{
				  start = lrMap[start].second;
				  i++;
				}

			  step++;
			  if (i == dir.size ())
				i = 0;
			}
		 
		  steps.push_back (step);
		}
		
    long long int lc=1;
	for (auto x:steps)
		{
		 lc=lcm(lc, x); 
		}
		cout<<lc;
	}


}
