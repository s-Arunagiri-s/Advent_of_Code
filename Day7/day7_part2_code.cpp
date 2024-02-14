#include <bits/stdc++.h>
using namespace std;
struct hand
{
    string cards;
    int bid;
    int rank;
};

unordered_map<char,int> ranking;

vector<hand> game;

bool compareCard(hand i1, hand i2)
{
    int i=0;
    while(i<5)
    {
        if(i1.cards[i]!=i2.cards[i])
    {
    return (ranking[i1.cards[i]] < ranking[i2.cards[i]]);
    }
    else
    i++;
    }
    
}
 
int
main ()
{
    

	ranking['A']=13;
	ranking['K']=12;
	ranking['Q']=11;
	ranking['J']=10;
	ranking['T']=9;
	ranking['9']=8;
	ranking['8']=7;
	ranking['7']=6;
	ranking['6']=5;
	ranking['5']=4;
	ranking['4']=3;
	ranking['3']=2;
	ranking['2']=1;
	ranking['J']=0;
	
  fstream file;
  string tp;
  string cards;
  string bid;
  file.open ("day5.txt", ios::in);
  if (file.is_open ())
	{

	  while (getline (file, tp))
		{
		  hand a;
		  cards=tp.substr(0,5);
		  bid = tp.substr(6,tp.size());
		  a.cards=cards;
		  a.bid=stoi(bid);
		  game.push_back(a);
		}
	}
	
	vector<hand> fiveOfAKind;
	vector<hand> fourOfAKind;
	vector<hand> fullHouse;
	vector<hand> threeOfAKind;
	vector<hand> twoPair;
	vector<hand> onePair;
	vector<hand> highCard;
	
	string temp;
	int arr[5]={0,0,0,0,0};
	
	for(auto x : game)
	{
	   temp=x.cards;
	   sort(temp.begin(),temp.end());
	   int k=1;
	   int j=0;
	   if(temp[0]=='J')
	   j=1;
	   cout<<temp<<"\n";
	   for(int i=1;i<5;i++)
	   {
	       if(temp[i]=='J')
	       {
	       j++;
	       }
	       if(temp[i]!=temp[i-1])
	       {
	           arr[k-1]++;
	           k=1;
	       }
	       else
	       {
	           k++;
	       }
	   }
	   arr[k-1]++;
	   
	   if(j>0)
	   {
	       if(j==5)
	       {
	           arr[4]=1;
	           j=0;
	       }
	       arr[j-1]--;
	       int ind=3;
	       while(ind>=0)
	       {
	           if(arr[ind]>0)
	           {
	               
	               arr[ind+j]++;
	           
	               arr[ind]--;
	               
	               break;
	               
	               
	           }
	           ind--;
	       }
	   }
	   cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<"\n";
	   if(arr[4]==1)
	   {
	       cout<<"fiveOfAKind\n";
	       fiveOfAKind.push_back(x);
	   }
	   else if(arr[3]==1 && arr[0]==1)
	   {
	       cout<<"fourOfAKindOfAKind\n";
	       fourOfAKind.push_back(x);
	   }
	   else if(arr[2]==1 && arr[1]==1)
	   {
	       cout<<"fullHouse\n";
	       fullHouse.push_back(x);
	   }
	   else if(arr[2]==1 && arr[0]==2)
	   {
	       cout<<"threeOfAKindOfAKind\n";
	       threeOfAKind.push_back(x);
	   }
	   else if(arr[1]==2 && arr[0]==1)
	   {
	       cout<<"twoPair\n";
	       twoPair.push_back(x);
	   }
	   else if(arr[1]==1 && arr[0]==3)
	   {
	       cout<<"onePair\n";
	       onePair.push_back(x);
	   }
	   else if(arr[0]==5)
	   {
	       cout<<"highCard\n";
	       highCard.push_back(x);
	   }
	   
	   arr[0]=0;
	   arr[1]=0;
	   arr[2]=0;
	   arr[3]=0;
	   arr[4]=0;
	   
	}
	
	//ranking
	int rank =0;
	
	vector<hand> finalOrder;
	
	sort(highCard.begin(),highCard.end(),compareCard);
	for(auto x: highCard)
	{
	    rank++;
	    x.rank=rank;
	    finalOrder.push_back(x);
	}
	
	sort(onePair.begin(),onePair.end(),compareCard);
	for(auto x: onePair)
	{
	    rank++;
	    x.rank=rank;
	    finalOrder.push_back(x);
	}
	
	sort(twoPair.begin(),twoPair.end(),compareCard);
	for(auto x: twoPair)
	{
	    rank++;
	    x.rank=rank;
	    finalOrder.push_back(x);
	}
	
	sort(threeOfAKind.begin(),threeOfAKind.end(),compareCard);
	for(auto x: threeOfAKind)
	{
	    rank++;
	    x.rank=rank;
	    finalOrder.push_back(x);
	}
	
	sort(fullHouse.begin(),fullHouse.end(),compareCard);
	for(auto x: fullHouse)
	{
	    rank++;
	    x.rank=rank;
	    finalOrder.push_back(x);
	}
	
	sort(fourOfAKind.begin(),fourOfAKind.end(),compareCard);
	for(auto x: fourOfAKind)
	{
	    rank++;
	    x.rank=rank;
	    finalOrder.push_back(x);
	}
	
	sort(fiveOfAKind.begin(),fiveOfAKind.end(),compareCard);
	for(auto x: fiveOfAKind)
	{
	    rank++;
	    x.rank=rank;
	    finalOrder.push_back(x);
	}
	long int ans=0;
	for(auto x: finalOrder)
	{
	   ans+= x.rank*x.bid;
	}
	cout<<ans;

}
