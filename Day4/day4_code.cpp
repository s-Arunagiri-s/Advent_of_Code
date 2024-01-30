#include <bits/stdc++.h>

using namespace std;
int main(){
    fstream file;
    int sum=0;
    string tp;
    int points=0;
    int match=0;
    int a=1;
    int finalans=0;
    file.open("day4.txt",ios::in);
    if(file.is_open())
    {
        while(getline(file,tp)){
            unordered_set<int> win;
            unordered_set<int> have;
            int start=tp.find(':');
            for(int i=start+2;tp[i]!='|';i++)
            {
                if(isdigit(tp[i]))
                   {
                       sum=sum*10;
                       sum+=int(tp[i]-'0');
                   }
                if(tp[i]==' ' && tp[i-1]!=' ')
                    {
                        win.insert(sum);
                        sum=0;
                    }
            }

            int sec=tp.find('|');
            for(int i=sec+2;i<=tp.size();i++)
            {
                if(isdigit(tp[i]))
                   {
                       sum=sum*10;
                       sum+=int(tp[i]-'0');
                   }
                if(tp[i]==' ')
                    {
                        have.insert(sum);
                        sum=0;
                    }
            }
            have.insert(sum);
            sum=0;

            unordered_set<int>::iterator itr;

            points=0;
            for (itr = have.begin(); itr != have.end();itr++)
            {
                 if (win.find(*itr) != win.end())
                 {
                     points++;
                 }

            }
            finalans+=pow(2,points-1);
            points=0;


    }
    cout<<"points: "<<finalans;
}}
