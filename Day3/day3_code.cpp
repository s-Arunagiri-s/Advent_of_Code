#include <bits/stdc++.h>
using namespace std;

int numgen(int i,int j,string &text)
{

    int num=0;
    while(isdigit(text[j])==1 && j>=0)
    {
        j--;
    }

    j++;

    while(isdigit(text[j]) && j<=text.size())
    {
        num+=int(text[j]-'0');
        num=num*10;
        text[j]='.';
        j++;
    }
    cout<<num/10<<" ";
    return num/10;
}

int main()
{
    fstream file;
    vector<string> text;
    string tp;
    long int sum=0;
    file.open("day1.txt",ios::in);
    if(file.is_open())
    {
      while(getline(file,tp))
        {
         text.push_back(tp);
        }
    }
    for(int i=0;i<text.size();i++)
    {
        for(int j=0;j<text[0].size();j++)
        {

            if(text[i][j]!='.' && isdigit(text[i][j])==0)
            {

             if(( isdigit(text[i-1][j-1])==1 && ((i-1>=0 && i<text.size()) && (j-1>=0 && j<text[0].size()))))
             {

                sum+=numgen(i-1,j-1,text[i-1]);
             }

             if(( isdigit(text[i-1][j])==1 && ((i-1>=0 && i<text.size()) && (j>=0 && j<text[0].size()))))
             {

                sum+=numgen(i-1,j,text[i-1]);
             }
             if(( isdigit(text[i-1][j+1])==1 && ((i-1>=0 && i<text.size()) && (j>=0 && j+1<text[0].size()))))
             {

                 sum+=numgen(i-1,j+1,text[i-1]);
             }
             if(( isdigit(text[i][j-1])==1 && ((i>=0 && i<text.size()) && (j-1>=0 && j<text[0].size()))))
             {

                 sum+=numgen(i,j-1,text[i]);
             }
             if(( isdigit(text[i][j+1])==1 && ((i>=0 && i<text.size()) && (j>=0 && j+1<text[0].size()))))
             {

                 sum+=numgen(i,j+1,text[i]);
             }
             if(( isdigit(text[i+1][j-1])==1 && ((i>=0 && i+1<text.size()) && (j-1>=0 && j<text[0].size()))))
             {

                 sum+=numgen(i+1,j-1,text[i+1]);
             }
             if(( isdigit(text[i+1][j])==1 && ((i>=0 && i+1<text.size()) && (j>=0 && j<text[0].size()))))
             {

                 sum+=numgen(i+1,j,text[i+1]);
             }
             if(( isdigit(text[i+1][j+1])==1 && ((i>=0 && i+1<text.size()) && (j>=0 && j+1<text[0].size()))))
             {

                 sum+=numgen(i+1,j+1,text[i+1]);
             }
            }

        }

    }
    cout<<"sum: "<<sum<<"\n";

}
