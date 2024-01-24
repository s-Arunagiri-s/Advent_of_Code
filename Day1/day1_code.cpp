#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    fstream file;
    file.open("day1.txt",ios::in);
    if(file.is_open())
    {
        string tp;
        int sum=0;
        int num=0;
        while(getline(file,tp)){
            for(int i=0;i<tp.length();i++)
            {
                if(tp[i]<='9' && tp[i]>='0')
                {
                    num=int(tp[i]-'0')*10;
                    break;
                }
            }
            for(int i=tp.length()-1;i>=0;i--)
            {
                if(tp[i]<='9' && tp[i]>='0')
                {
                    num+=int(tp[i]-'0');
                    break;
                }
            }
            cout<<num<<"\n";
            sum+=num;
            num=0;
        }
        cout<<sum;
    }
}
